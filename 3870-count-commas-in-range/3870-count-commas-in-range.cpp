class Solution {
public:
    int countCommas(int n) {
        // ======= my approach =======
        // if (1 <= n <= 999) {
        //     return 0;
        // } else if (1000 <= n <= 99999) {
        // }

        // ======= optimized approach =======
        return (n > 999) * (n - 999);
    }
};