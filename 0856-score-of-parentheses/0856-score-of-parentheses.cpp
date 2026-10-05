class Solution {
public:
    int scoreOfParentheses(string s) {

        int depth = 0, score = 0; 

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                depth++;
            }
            else 
            {
                depth--; 

                // If this is "()"
                if (s[i - 1] == '(')
                {
                    score = score + pow(2, depth);
                }
            }
        }
        return score; 
    }
};