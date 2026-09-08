class Solution {
public:
    int countCommas(int n) {
        // ======= my approach =======
         // Numbers below 1000 have no commas
        // if (n < 1000) {
        //     return 0;
        // }
        // Every number from 1000 to n has exactly one comma
        // return n - 999;
        // Time Complexity: O(1)
        // Space Complexity: O(1)

        // ======= another linear appraoch =======
        // Every number from 1,000 to n contains at least one comma. Numbers below 1,000 do not contain a comma.
        // So we simply count how many numbers in the range 1 to n are at least 1,000.
        // int count = 0;
        // for (int i = 1; i <= n; i++) {
        //     if (i >= 1000) {
        //         count++;
        //     }
        // }
        // return count;

        // ======= optimized approach =======
        // If n≥1,000, the count of numbers containing a comma is n−999.
        // If n<1,000, the count is 0.
        // return (n > 999) * (n - 999);
        // Time complexity: O(1)
        // Space complexity: O(1)

        // ======= another optimized approach =======
        return max(n - 999, 0);
        // Time complexity: O(1).
        // Space complexity: O(1).
    }
};