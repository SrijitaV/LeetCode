
class Solution {
public:
    string addStrings(string num1, string num2) {

        int i = num1.length() - 1;
        int j = num2.length() - 1;

        int carry = 0;
        string ans = "";

        // Traverse both strings from right to left
        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            // Add digit from num1 if available
            if (i >= 0) {
                sum = sum + num1[i] - '0';
                i--;
            }

            // Add digit from num2 if available
            if (j >= 0) {
                sum = sum + num2[j] - '0';
                j--;
            }

            // Store the current digit
            ans += ((sum % 10) + '0');

            // Update carry
            carry = sum / 10;
        }

        // Reverse because addition was performed right to left
        reverse(ans.begin(), ans.end());

        return ans;

        // Time Complexity:
        // O(max(n,m))
        // where n and m are the lengths of the two strings.
        // We traverse both strings once.

        // Space Complexity:
        // O(max(n,m))
        // for storing the resulting string.
    }
};
