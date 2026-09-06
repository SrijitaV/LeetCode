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
    }
};