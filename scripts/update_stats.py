
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUTPUT = ROOT / "stats.json"

# Solution file types supported by this repository.
SOLUTION_EXTENSIONS = {
    ".cpp", ".cc", ".c", ".h", ".hpp",
    ".py", ".sql", ".java", ".js", ".ts",
    ".go", ".rs", ".cs", ".php", ".rb",
    ".swift", ".kt"
}

DIFFICULTIES = ("easy", "medium", "hard", "unknown")


def sha1_file(path):
    """Create a SHA-1 hash of a file's contents."""
    digest = hashlib.sha1()

    with path.open("rb") as file:
        for chunk in iter(lambda: file.read(8192), b""):
            digest.update(chunk)

    return digest.hexdigest()


def get_difficulty(folder):
    """Read difficulty from the problem's generated README."""
    readme = folder / "README.md"

    if not readme.exists():
        return "unknown"

    content = readme.read_text(encoding="utf-8", errors="ignore")

    # LeetHub READMEs commonly contain <h3>Easy</h3>.
    match = re.search(
        r"<h3>\s*(Easy|Medium|Hard)\s*</h3>",
        content,
        re.IGNORECASE
    )

    # Also support an explicit Markdown difficulty heading.
    if not match:
        match = re.search(
            r"(?im)^#{1,6}\s*(Easy|Medium|Hard)\s*$",
            content
        )

    if not match:
        return "unknown"

    return match.group(1).lower()


def main():
    counts = {difficulty: 0 for difficulty in DIFFICULTIES}
    shas = {}

    # Track the root README separately.
    root_readme = ROOT / "README.md"

    if root_readme.exists():
        shas["README.md"] = {
            "": sha1_file(root_readme)
        }

    # Only inspect folders that look like LeetCode problem folders.
    for folder in sorted(ROOT.iterdir()):
        if not folder.is_dir():
            continue

        if not re.match(r"^\d+-[a-z0-9-]+$", folder.name, re.I):
            continue

        solution_files = [
            path for path in folder.rglob("*")
            if path.is_file()
            and path.suffix.lower() in SOLUTION_EXTENSIONS
            and ".git" not in path.parts
        ]

        # Ignore folders without a recognized solution file.
        if not solution_files:
            continue

        difficulty = get_difficulty(folder)
        counts[difficulty] += 1

        file_hashes = {}

        # Record hashes of files belonging to this problem.
        for path in sorted(folder.rglob("*")):
            if not path.is_file() or ".git" in path.parts:
                continue

            relative_path = path.relative_to(folder).as_posix()
            file_hashes[relative_path] = sha1_file(path)

        file_hashes["difficulty"] = difficulty
        shas[folder.name] = file_hashes

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
    print(f"Total tracked problems: {stats['leetcode']['solved']}")
    print(
        "Easy: {easy}, Medium: {medium}, Hard: {hard}, "
        "Unknown: {unknown}".format(**counts)
    )


if __name__ == "__main__":
    main()
