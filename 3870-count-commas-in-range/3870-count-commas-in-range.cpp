class Solution {
public:
    int countCommas(int n) {
        // ======= my approach =======
        if (n < 1000) {
            return 0;
        }
        return n - 999;

        // ======= another linear appraoch =======
        // int count = 0;
        // for (int i = 1; i <= n; i++) {
        //     if (i >= 1000) {
        //         count++;
        //     }
        // }
        // return count;

        // ======= optimized approach =======
        // return (n > 999) * (n - 999);

        // ======= another optimized approach =======
        // return max(n - 999, 0);
    }
};