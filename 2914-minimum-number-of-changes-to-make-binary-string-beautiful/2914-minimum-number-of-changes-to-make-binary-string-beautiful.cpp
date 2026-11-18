
class Solution {
public:
    int minChanges(string s) {

        // --------------------------------------------------------------

        // ------------------ my brute force approach ------------------

        // Intuition

        // - According to Hint 1, every valid substring of even length
        // can be further divided into substrings of length exactly 2.
        // - Therefore, we can divide the entire string into
        // disjoint pairs of size 2.
        // - For each pair:
        //   - If both characters are the same (00 or 11),
        // no changes are required.
        //   - If both characters are different (01 or 10),
        // we need to change exactly one character.
        // - We traverse every pair and increment ans
        // whenever the two characters are different.
        // - Finally, return the total number of changes.

        // final result
        int ans = 0;

        // i and j represent a pair of adjacent characters
        int i = 0, j = 1;

        // Traverse the string by considering pairs of size 2
        while (j < s.length()) {

            // If both characters are different,
            // we need to change one of them to make the pair beautiful
            if (s[i] != s[j]) {
                ans++;
            }

            // Move to the next pair
            i += 2;
            j += 2;
        }

        // Return the minimum number of changes required
        return ans;

        // Complexity Analysis

        // - Time Complexity: O(n)
        // We traverse the string once, processing two characters in every iteration. 
        // Hence, O(n/2) = O(n).

        // - Space Complexity: O(1)
        // We use only a constant number of variables (ans, i, and j), 
        // irrespective of the input size.
        
    }
};
