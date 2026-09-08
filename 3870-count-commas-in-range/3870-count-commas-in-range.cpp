class Solution {
public:
    int countCommas(int n) {
        // ======= my approach =======
        // if (1 <= n <= 999) {
        //     return 0;
        // } else if (1000 <= n <= 99999) {
        // }

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
        return max(n - 999, 0);
    }
};