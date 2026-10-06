class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0, add = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++; // store unmatched '('
            } else {    // s[i] == ')'
                if (open > 0) {
                    open--; // match ')' with '('
                } else {
                    add++; // need to add '('
                }
            }
        }
        return add + open; // add ')' for remaining '('

        // Time : O(n) ~ Traverse the string once
        // Space :	O(1) ~ Only two variables used
    }
};