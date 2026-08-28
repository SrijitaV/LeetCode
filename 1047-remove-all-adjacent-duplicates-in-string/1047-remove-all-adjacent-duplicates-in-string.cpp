class Solution {

public:

    string removeDuplicates(string s) {

        // 'ans' will store the final string after removing adjacent duplicates
        string ans = "";

        // Start traversing the given string from index 0
        int i = 0;

        // Continue until we reach the end of the string
        while (i < s.length()) {

            // Check if 'ans' already contains at least one character
            if (ans.length() > 0) {

                // Compare the last character of 'ans' with the current
                // character of 's'
                if (ans[ans.length() - 1] == s[i]) {

                    // If they are the same, remove the last character
                    // from 'ans' because they form a duplicate pair
                    ans.pop_back();

                } else {

                    // If they are different, add the current character
                    // to 'ans'
                    ans.push_back(s[i]);
                }

            } else {

                // If 'ans' is empty, simply add the current character
                ans.push_back(s[i]);
            }

            // Move to the next character in the input string
            i++;
        }

        // Return the final string with all adjacent duplicates removed
        return ans;
    }
};