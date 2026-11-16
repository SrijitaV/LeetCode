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

                // convert the digit sum into a string and
                // append it to newString
                newString = newString + to_string(sum);
            }

            // update s with the newly constructed string
            // for the next round
            s = newString;
        }

        // asked ~ Return s after all rounds have been completed.
        return s;

        // Complexity Analysis
        // Let n be the initial length of the string and k be the group size.

        // Time Complexity: O(n log_k n)
        // - The outer while loop executes approximately log_k n rounds.
        // - In each round, we traverse the current string to calculate the
        // digit sums.
        // - The string length reduces approximately by a factor of k in each
        // round.
        // - Therefore, the total work is bounded by:
        // O(n + \frac{n}{k} + \frac{n}{k^2} + \cdots\right)
        // This geometric series is O(n) for k >= 2.
        // So the tighter time complexity is actually O(n).

        // Space Complexity: O(n)
        // - temp stores a substring.
        // - newString stores the newly constructed string.
        // - Both require at most linear space relative to the initial string
        // length.

        // Final
        // TC: O(n)
        // SC: O(n)
    }
};