class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.size() - 1;

        // skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // count the last word
        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }

        return ans;
    }
};