class Solution {
public:
    int maximum69Number(int num) {

        // Convert the integer into a string
        string s = to_string(num);

        // Traverse the string from left to right
        for (int i = 0; i < s.length(); i++) {
            // We start from the left because changing a digit at a higher place
            // value produces a bigger number.

            // Find the first 6
            if (s[i] == '6') {

                // Replace 6 with 9
                s[i] = '9';

                // Stop the loop
                break;
                // break immediately terminates the loop after changing the
                // first 6. Why? Because we are allowed to change at most one
                // digit, and the leftmost 6 gives the maximum possible
                // increase.
            }
        }

        // Convert the string back into an integer
        // stoi() means string to integer.
        return stoi(s);

        // Let n be the number of digits in num.
        // - Time complexity: O(n), because converting, traversing and
        // converting back take linear time.
        // - Space complexity: O(n), because we store the digits in a string.
    }
};