class Solution {
public:
    string digitSum(string s, int k) {

        // given ~ A round can be completed
        // if the length of s is greater than k.
        while (s.length() > k) {

            // createing an empty string
            // to store the result of the current round
            string newString = "";

            // divide the string into consecutive groups of size k
            for (int i = 0; i < s.length(); i += k) {

                // extracting a substring of size k
                // the last group can have fewer than k characters
                string temp = s.substr(i, k);

                // initialize sum to calculate the sum of digits in each group.
                int sum = 0;

                // iterate through each character of the extracted group
                for (int j = 0; j < temp.length(); j++) {

                    // convert each character into an integer and add it to sum
                    sum = sum + temp[j] - '0';
                }

                // convert the digit sum into a string and append it to
                // newString
                newString = newString + to_string(sum);
            }

            // update s with the newly constructed string for the next round
            s = newString;
        }

        // asked ~ Return s after all rounds have been completed.
        return s;
    }
};