class Solution {
public:
    int minOperations(string s) {

        int n = s.size(); // given string ki size

        // check whether the string is already sorted
        // if yes, no operation is required
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // if string length is 2, only single-character
        // substrings can be selected, which cannot change the string
        if (n == 2) {
            return -1;
        }

        // find the smallest and largest characters in the string
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // if the first character is the minimum OR
        // the last character is the maximum,
        // we can sort the string in just one operation
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // check the special case where:
        // first character is the maximum
        // last character is the minimum
        // AND both maximum and minimum occur only once
        if ((s[0] == mx && s[n - 1] == mn) &&
            (count(s.begin(), s.end(), mx) == 1) &&
            (count(s.begin(), s.end(), mn) == 1)) {
            // in this special case, three operations are needed
            return 3;
            // to check whether the maximum character is unique, use
            // count(s.begin(), s.end(), mx) == 1
            // to check whether the minimum character is unique, use
            // count(s.begin(), s.end(), mn) == 1
            // both conditions must be true for the special three-operation
        }

        // all remaining unsorted strings
        // all remaining unsorted strings can be sorted
        // in two operations
        return 2;

        // Time Complexity: O(n)
        // Operation | Complexity
        // s.size() | O(1)
        // is_sorted(s.begin(), s.end()) | O(n)
        // min_element() | O(n)
        // max_element() | O(n)
        // count() for maximum | O(n)
        // count() for minimum | O(n)
        // these operations run sequentially, not nested inside one another
        // therefore, we add their complexities
        // O(n) + O(n) + O(n) + O(n) = O(n)

        // Space Complexity: O(1)
        // here only use a few variables:
        // n for the string length
        // mn for the minimum character
        // mx for the maximum character
        // The algorithms used here don't require additional data structures
        // proportional to the input size.
    }
};