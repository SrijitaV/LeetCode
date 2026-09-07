class Solution {
public:
    // To determine if a number is ugly, we remove all factors of 2, 3, and 5. If the result is 1, then it’s ugly.
    bool isUgly(int n) {
        // Return False if the number is less than or equal to 0.
        if (n <= 0) {
            return false;
        }
        // Continuously divide the number by 2, 3, and 5 while it's divisible.
        while ((n % 2) == 0) {
            n /= 2;
        }
        while ((n % 3) == 0) {
            n /= 3;
        }
        while ((n % 5) == 0) {
            n /= 5;
        }
        // If the result is 1 after all divisions, it's an ugly number.
        return n == 1;
    }
    // This approach reduces the number to its core factors and ensures no primes other than 2, 3, or 5 exist.

    // Complexity
    // Time Complexity:
    //     ( O(\log n) ) — the number is divided by 2, 3, or 5 repeatedly.
    // Space Complexity:
    //     ( O(1) ) — constant space usage.
};