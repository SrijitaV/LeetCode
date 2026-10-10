class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            int r1 = 0, r2 = 0, r3 = 0;

            for (int j = 0; j < word.length(); j++) {
                char c = tolower(word[j]);

                if (row1.find(c) != string::npos) {
                    r1++;
                } else if (row2.find(c) != string::npos) {
                    r2++;
                } else {
                    r3++;
                }
            }

            if (r1 == word.size() || 
                r2 == word.size() ||
                r3 == word.size()) {
                result.push_back(word);
            }
        }

        return result;
    }
};