class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, openBrackets = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                openBrackets--;
            }

            ans = max(ans, openBrackets);
        }
        return ans;

        // Time: O(n)
        // Space: O(1)
        
    }
};