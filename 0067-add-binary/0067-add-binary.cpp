class Solution {
public:
    string addBinary(string a, string b) {

        // ---------------- optimized appraoch ----------------

        // -------------- my appraoch ~ brute force ---------------

        int carry = 0;
        string ans = "";

        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0) {

            // Get digit from a, or 0 if i < 0
            int digitA = 0;
            if (i >= 0) {
                // '0' and '1' are characters because a and b are strings. We
                // use - '0' to convert them into integers for addition.
                digitA = a[i] - '0'; // Convert char '0'/'1' to integer 0/1
            }

            // Get digit from b, or 0 if j < 0
            int digitB = 0;
            if (j >= 0) {
                // '0' and '1' are characters because a and b are strings. We
                // use - '0' to convert them into integers for addition.
                digitB = b[j] - '0'; // Convert char '0'/'1' to integer 0/1
            }

            // Add:
            // digitA + digitB + carry
            int sum = digitA + digitB + carry;

            // Decide the current answer digit
            ans +=
                ((sum % 2) + '0'); // Convert integer 0/1 back to char '0'/'1'

            // Update carry
            carry = sum / 2;

            // Move i and j
            i--;
            j--;
        }

        // What if carry is still 1 here?
        if (carry == 1) {
            ans = ans + '1';
        }

        // Since we're adding from right to left,
        // what should we do with ans?
        reverse(ans.begin(), ans.end());

        return ans;

        // Time Complexity  : O(max(n, m))
        // Space Complexity : O(max(n, m) )
    }
};