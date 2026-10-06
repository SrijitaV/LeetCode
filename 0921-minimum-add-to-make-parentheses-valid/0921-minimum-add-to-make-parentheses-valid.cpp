class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0, add = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else { // s[i] == ')'
                if (open > 0) {
                    open--;
                } else {
                    add++;
                }
            }
        }
        return add + open;
    }
};