class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        // storing all the three keyboard rows
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        // to store the words which can be typed using one row only
        vector<string> result;

        // iterating through each word
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            // counting how many characters belong to each row
            int r1 = 0, r2 = 0, r3 = 0;

            // iterating through each character of the current word
            for (int j = 0; j < word.length(); j++) {
                char c = tolower(word[j]); // converting character to lowercase

                // checking if the character belongs to row 1
                if (row1.find(c) != string::npos) {
                    r1++;
                }
                // checking if the character belongs to row 2
                else if (row2.find(c) != string::npos) {
                    r2++;
                }
                // otherwise the character belongs to row 3
                else {
                    r3++;
                }
            }

            // if all characters belong to the same row, store the word
            if (r1 == word.size() || r2 == word.size() || r3 == word.size()) {
                result.push_back(word);
            }
        }

        // returning all valid words
        return result;

        // Time complexity: O(nk)
        // assuming the keyboard row strings have fixed length, where n is the
        // number of words and k is the average word length.
        // Auxiliary space: O(1)
        // excluding the output, since the three keyboard rows have fixed
        // lengths.
    }
};