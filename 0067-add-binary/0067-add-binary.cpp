class Solution {
public:
    string addBinary(string a, string b) {

        // ---------------- optimized appraoch ----------------
        int carry = 0;
        string ans;

        int i = a.length() - 1;
        int j = b.length() - 1;

        // we enter a while loop that iterates until we have processed all
        // digits in both binary numbers and there is no more carry-over value
        // left. in each iteration, we add the digits from both numbers at the
        // current position and the carry-over value (if any), and append the
        // result. we also update the carry-over value based on the sum of the
        // digits.

        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0) {
                carry += a[i--] - '0';
            }
            if (j >= 0) {
                carry += b[j--] - '0';
            }
            ans += (carry % 2) + '0';
            carry /= 2;
        }

        // In each iteration, the current position in each binary number is
        // moved one digit to the left (if there are any digits left to
        // process) by decrementing the value of i and j. If there is a
        // carry-over value from the previous iteration or the addition of
        // the two digits produces a carry-over value, we set the value of
        // 'carry' to 1; otherwise, we set it to 0. We also append the sum
        // of the digits to the StringBuilder object by computing the
        // remainder of 'carry' divided by 2 (which is either 0 or 1).
        // Finally, we update the value of 'carry' by dividing it by 2
        // (which gives either 0 or 1) so that we can carry over any
        // remaining value to the next iteration. After the while loop
        // completes, we reverse the StringBuilder object and convert it to
        // a string using the toString() method. This gives us the sum of
        // the two binary numbers in binary format.

        reverse(begin(ans), end(ans));
        return ans;

        // Time complexity : O(max|a|,|b|)
        // Space complexity : O(max|a|,|b|)

        // -------------- my appraoch ~ brute force ---------------

        // int carry = 0;
        // string ans = "";

        // int i = a.length() - 1;
        // int j = b.length() - 1;

        // while (i >= 0 || j >= 0) {

        //     // Get digit from a, or 0 if i < 0
        //     int digitA = 0;
        //     if (i >= 0) {
        //         // '0' and '1' are characters because a and b are strings. We
        //         // use - '0' to convert them into integers for addition.
        //         digitA = a[i] - '0'; // Convert char '0'/'1' to integer 0/1
        //     }

        //     // Get digit from b, or 0 if j < 0
        //     int digitB = 0;
        //     if (j >= 0) {
        //         // '0' and '1' are characters because a and b are strings. We
        //         // use - '0' to convert them into integers for addition.
        //         digitB = b[j] - '0'; // Convert char '0'/'1' to integer 0/1
        //     }

        //     // Add:
        //     // digitA + digitB + carry
        //     int sum = digitA + digitB + carry;

        //     // Decide the current answer digit
        //     ans +=
        //         ((sum % 2) + '0'); // Convert integer 0/1 back to char
        //         '0'/'1'

        //     // Update carry
        //     carry = sum / 2;

        //     // Move i and j
        //     i--;
        //     j--;
        // }

        // // What if carry is still 1 here?
        // if (carry == 1) {
        //     ans = ans + '1';
        // }

        // // Since we're adding from right to left,
        // // what should we do with ans?
        // reverse(ans.begin(), ans.end());

        // return ans;

        // // Time Complexity  : O(max(n, m))
        // // Space Complexity : O(max(n, m) )
    }
};