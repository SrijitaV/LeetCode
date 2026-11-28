class Solution {
public:
    int findNumbers(vector<int>& nums) {

        // ------------------------------------------------------------------

        // -------------- Approach: String Conversion Approach --------------

        // Intuition:
        // Convert each integer into a string using to_string().
        // Use length() to calculate the number of digits.
        // If the number of digits is even, increment count.
        // Finally, return the count of numbers having even digits.

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            string temp = to_string(nums[i]);

            int check = temp.length();

            if (check % 2 == 0) {
                count++;
            }
        }

        return count;

        // Time Complexity: O(N * D)
        // - N = number of elements in the array.
        // - D = maximum number of digits in an integer.
        // - We traverse the array once.
        // - Converting each integer to a string takes O(D).
        // - Checking the string length takes O(1).

        // Space Complexity: O(D)
        // - A temporary string is created for each number.
        // - It stores at most D digits.
        // - Only one temporary string is used at a time.
    }
};
