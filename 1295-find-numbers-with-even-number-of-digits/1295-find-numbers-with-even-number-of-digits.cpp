class Solution {
public:
    int findNumbers(vector<int>& nums) {

        // ------------------- Approach: Logarithmic Approach -------------------

// Intuition:
// - Use log10(n) to calculate the number of digits.
// - Take the floor value and add 1.
// - Check whether the digit count is even.

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            int digits = (int)log10(nums[i]) + 1;

            if (digits % 2 == 0) {
                count++;
            }
        }

        return count;

        // TC: O(N)
// SC: O(1)

        // ----------------------------------------------------------------------

        // // -------- Approach: Mathematical Approach (Repeated Division) --------

        // // Intuition:
        // // - Divide each number by 10 repeatedly.
        // // - Every division removes the last digit.
        // // - Count the number of divisions.
        // // - If the digit count is even, increment the answer.

        // int count = 0;

        // for (int i = 0; i < nums.size(); i++) {

        //     int n = nums[i];
        //     int digits = 0;

        //     while (n > 0) {
        //         digits++;
        //         n = n / 10;
        //     }

        //     if (digits % 2 == 0) {
        //         count++;
        //     }
        // }

        // return count;

        // // TC : O(N* D) 
        // // SC : O(1)

        // ----------------------------------------------------------------------

        // // -------------- Approach: String Conversion Approach --------------

        // // Intuition:
        // // Convert each integer into a string using to_string().
        // // Use length() to calculate the number of digits.
        // // If the number of digits is even, increment count.
        // // Finally, return the count of numbers having even digits.

        // int count = 0;

        // for (int i = 0; i < nums.size(); i++) {

        //     string temp = to_string(nums[i]);

        //     int check = temp.length();

        //     if (check % 2 == 0) {
        //         count++;
        //     }
        // }

        // return count;

        // // Time Complexity: O(N * D)
        // // - N = number of elements in the array.
        // // - D = maximum number of digits in an integer.
        // // - We traverse the array once.
        // // - Converting each integer to a string takes O(D).
        // // - Checking the string length takes O(1).

        // // Space Complexity: O(D)
        // // - A temporary string is created for each number.
        // // - It stores at most D digits.
        // // - Only one temporary string is used at a time.
    }
};
