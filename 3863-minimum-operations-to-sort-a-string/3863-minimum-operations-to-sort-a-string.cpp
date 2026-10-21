class Solution {
public:
    int minOperations(string s) {

        int n = s.size(); /// given string ks size

        // already sorted array
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // only single-character substring are allowed
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // one operation is sufficient
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // three operations needed when the
        // first character is the unique maximum
        // and the last characrter is the unique minimum
        if ((s[0] == mx && s[n - 1] == mn) &&
            (count(s.begin(), s.end(), mx) == 1) &&
            (count(s.begin(), s.end(), mn) == 1)) {
            return 3;
            // to check whether the maximum character is unique, use
            // count(s.begin(), s.end(), mx) == 1
            // to check whether the minimum character is unique, use
            // count(s.begin(), s.end(), mn) == 1
            // both conditions must be true for the special three-operation
        }

        // all remaining unsorted strings
        return 2;
    }
};