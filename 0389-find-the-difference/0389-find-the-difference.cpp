class Solution {
public:
    char findTheDifference(string s, string t) {
        int total_s = 0, total_t = 0;
        for (int i = 0; i < s.length(); i++) {
            total_s = total_s + s[i];
        }
        for (int i = 0; i < t.length(); i++) {
            total_t = total_t + t[i];
        }
        int ans = total_t - total_s;
        return ans; 
    }
};