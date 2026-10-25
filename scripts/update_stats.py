
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUTPUT = ROOT / "stats.json"

SOLUTION_EXTENSIONS = {
    ".cpp", ".cc", ".c", ".h", ".hpp",
    ".py", ".sql", ".java", ".js", ".ts",
    ".go", ".rs", ".cs", ".php", ".rb",
    ".swift", ".kt"
}

DIFFICULTIES = ("easy", "medium", "hard", "unknown")


def sha1_file(path):
    """Generate a SHA-1 hash of a file's contents."""
    digest = hashlib.sha1()

    with path.open("rb") as file:
        for chunk in iter(lambda: file.read(8192), b""):
            digest.update(chunk)

    return digest.hexdigest()


def get_difficulty(folder):
    """Detect difficulty from common LeetCode README formats."""
    readme = folder / "README.md"

    if not readme.exists():
        return "unknown"

    content = readme.read_text(
        encoding="utf-8",
        errors="ignore"
    )

    # Search the beginning of the README to avoid matching
    # difficulty words mentioned in unrelated explanations.
    header = content[:3000]

    patterns = [
        # HTML headings: <h3>Easy</h3>, <h2>Medium</h2>, etc.
        r"<h[1-6]\b[^>]*>\s*(Easy|Medium|Hard)\s*</h[1-6]\s*>",

        # Markdown headings: ## Easy, ### Medium, etc.
        r"(?im)^\s*#{1,6}\s*(Easy|Medium|Hard)\s*$",

        # Difficulty: Easy or **Difficulty:** Medium
        r"(?im)^\s*(?:[-*]\s*)?"
        r"\*{0,2}Difficulty\*{0,2}\s*[:\-]\s*"
        r"\*{0,2}(Easy|Medium|Hard)\b",

        # HTML bold text: <strong>Easy</strong> or <b>Hard</b>
        r"<(?:strong|b)\b[^>]*>\s*"
        r"(Easy|Medium|Hard)\s*</(?:strong|b)\s*>",
    ]

    for pattern in patterns:
        match = re.search(pattern, header, re.IGNORECASE)

        if match:
            return match.group(1).lower()

    return "unknown"


def get_problem_number(folder_name):
    """Extract the LeetCode problem number from a folder name."""
    match = re.match(r"^(\d+)-[a-z0-9-]+$", folder_name, re.IGNORECASE)

    if not match:
        return None

    return int(match.group(1))


def main():
    counts = {difficulty: 0 for difficulty in DIFFICULTIES}
    shas = {}
    problems_by_number = {}

    # Track the root README.
    root_readme = ROOT / "README.md"

    if root_readme.exists():
        shas["README.md"] = {
            "": sha1_file(root_readme)
        }

    # Find all folders that look like LeetCode problems.
    for folder in sorted(ROOT.iterdir()):
        if not folder.is_dir():
            continue

        problem_number = get_problem_number(folder.name)

        if problem_number is None:
            continue

        # Require at least one recognized solution file.
        solution_files = [
            path for path in folder.rglob("*")
            if path.is_file()
            and path.suffix.lower() in SOLUTION_EXTENSIONS
            and ".git" not in path.parts
        ]

        if not solution_files:
            continue

        difficulty = get_difficulty(folder)

        # Hash all files inside the problem folder.
        file_hashes = {}

        for path in sorted(folder.rglob("*")):
            if not path.is_file() or ".git" in path.parts:
                continue

            relative_path = path.relative_to(folder).as_posix()
            file_hashes[relative_path] = sha1_file(path)

        file_hashes["difficulty"] = difficulty

        # Keep each folder's hashes under its original folder name.
        shas[folder.name] = file_hashes

        # Group differently named folders by problem number.
        problems_by_number.setdefault(problem_number, []).append({
            "folder": folder.name,
            "difficulty": difficulty
        })

    # Count each LeetCode problem number only once.
    for problem_number, entries in problems_by_number.items():
        # Prefer a known difficulty if duplicate folders disagree.
        known_difficulties = [
            entry["difficulty"]
            for entry in entries
            if entry["difficulty"] != "unknown"
        ]

        if known_difficulties:
            difficulty = known_difficulties[0]
        else:
            difficulty = "unknown"

        counts[difficulty] += 1

    stats = {
        "leetcode": {
            **counts,
            "solved": sum(counts.values()),
            "shas": shas
        }
    }

    OUTPUT.write_text(
        json.dumps(stats, indent=2, ensure_ascii=False) + "\n",
        encoding="utf-8"
    )

    print(f"Stats generated: {OUTPUT}")
    print(f"Unique problems tracked: {stats['leetcode']['solved']}")
    print(
        "Easy: {easy}, Medium: {medium}, Hard: {hard}, "
        "Unknown: {unknown}".format(**counts)
    )


if __name__ == "__main__":
    main()
