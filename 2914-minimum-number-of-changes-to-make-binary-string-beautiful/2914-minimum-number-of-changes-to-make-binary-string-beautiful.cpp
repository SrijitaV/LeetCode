
class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int i = 0, j = 1;

        while (j < s.length()) {
            if (s[i] != s[j]) {
                ans++;
            }

            i += 2;
            j += 2;
        }

        return ans;
    }
};
