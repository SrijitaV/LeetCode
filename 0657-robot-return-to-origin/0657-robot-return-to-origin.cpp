class Solution {
public:
    bool judgeCircle(string moves) {

        // --------------- Using X and Y Coordinates-------------------

        // Instead of counting the frequency of each direction separately,
        // we maintain the robot's current position using two variables:
        // - x = horizontal position (Left and Right)
        // - y = vertical position (Up and Down)

        // ye robot ki current position track karega
        int x = 0, y = 0;

        // ye moves string ko traverse karega
        for (int i = 0; i < moves.length(); i++) {

            if (moves[i] == 'U') {
                y++;  // ek step upar
            }
            else if (moves[i] == 'D') {
                y--;  // ek step neeche
            }
            else if (moves[i] == 'L') {
                x--;  // ek step left
            }
            else {
                x++;  // ek step right
            }
        }

        // agar dono coordinates 0 hain toh robot origin par hai
        return x == 0 && y == 0;

// Time Complexity: O(n)
// - We traverse the string once.
// - Each move takes constant time, O(1).
// - Therefore, O(n), where n is the length of the string.

// Space Complexity: O(1)
// - We use only two integer variables, x and y.
// - No extra array or data structure is required.

        // -------------------------------------------------------------------------

        // --------------- my brute force approach -------------------

        // // ye charo directions ki frequency count karega
        // int u = 0, d = 0, l = 0, r = 0;

        // // ye moves string ko traverse karega
        // for (int i = 0; i < moves.length(); i++) {

        //     if (moves[i] == 'U') {
        //         u++;
        //     } else if (moves[i] == 'D') {
        //         d++;
        //     } else if (moves[i] == 'L') {
        //         l++;
        //     } else {
        //         r++;
        //     }
        // }

        // // agar up-down aur left-right equal hain
        // // toh robot wapas origin par aa jayega
        // return (u == d && l == r);

        // //         Time Complexity (TC) ~ O(n)
        // // - n = length of the moves string.
        // // - We traverse the string exactly once.
        // // - Each character takes constant time to process.
        // // Therefore, TC = O(n).

        // // Space Complexity (SC) ~ O(1)
        // // - We use only four integer variables: u, d, l, r.
        // // - No extra data structure is used.
        // // - Space doesn't depend on the input size.
        // // Therefore, SC = O(1).
    }
};