class Solution {
public:
    bool judgeCircle(string moves) {

        // -------------------------------------------------------------------------

        // my brute force approach 

        // ye charo directions ki frequency count karega
        int u = 0, d = 0, l = 0, r = 0;

        // ye moves string ko traverse karega
        for (int i = 0; i < moves.length(); i++) {

            if (moves[i] == 'U') {
                u++;
            }
            else if (moves[i] == 'D') {
                d++;
            }
            else if (moves[i] == 'L') {
                l++;
            }
            else {
                r++;
            }
        }

        // agar up-down aur left-right equal hain
        // toh robot wapas origin par aa jayega
        return (u == d && l == r);

//         Time Complexity (TC) ~ O(n)
// - n = length of the moves string.
// - We traverse the string exactly once.
// - Each character takes constant time to process.
// Therefore, TC = O(n).

// Space Complexity (SC) ~ O(1)
// - We use only four integer variables: u, d, l, r.
// - No extra data structure is used.
// - Space doesn't depend on the input size.
// Therefore, SC = O(1).

    }
};