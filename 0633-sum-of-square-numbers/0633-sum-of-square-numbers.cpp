class Solution {
public:
    bool judgeSquareSum(int c) {
        // ========== nested loop approach ==========
        // for (int i = 0; (i * i) <= c; i++) {
        //     for (int j = 0; (j * j) <= c; j++) {
        //         if (((i * i) + (j * j)) == c) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // ========== optimized appraoch ==========
        for (long long a = 0; (a * a) <= c; a++) {
            long long b = (c - (a * a));
            long long root = sqrt(b);
            if ((root * root) == b) {
                return true;
            }
        }
        return false;
        /*
        For each possible a, calculate:       b² = c - a²

        Then check whether b² is a perfect square by taking its square root.

        a * a <= c ensures we only check valid values of a.
        root = sqrt(b) gives the possible value of b.
        If root * root == b, then a² + b² = c, so return true.
        If no valid pair is found, return false.
        Time Complexity

        The loop runs up to √c times, and sqrt() takes constant time.

        Time: O(√c)
        Space: O(1)
        */
    }
};