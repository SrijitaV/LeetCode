class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {

        // If value == 1, no valid array exists.
        if (value == 1) {
            return -1;
        }

        // Otherwise, let p be the smallest prime factor of value.
        // Any predecessor of value is at most (value - p),
        // and any successor is at least (value + p). Both expressions are even.
        // Find the smallest prime factor of value
        int p = value;

        // Why start i from 2?
        // - Because 1 is not a prime number.
        // - The smallest possible prime factor is 2.
        // - So we start checking divisibility from 2.
        // Why i * i <= value?
        // - This is the most important part.
        // - We only need to check factors up to the square root of the number.
        for (int i = 2; i * i <= value; i++) {
            // Why value % i == 0?
            // - This checks whether i divides value completely.
            // - If the condition is true, we have found a factor.
            if (value % i == 0) {
                // Why p = i?
                // - We store the factor we just found.
                // - Since we are checking numbers in increasing order,
                // the first factor we find is the smallest prime factor.
                p = i;
                // Once we find the smallest prime factor,
                // there is no need to check further.
                // We exit the loop immediately.
                break;
            }
        }

        // Check whether the left side is possible
        // This condition checks whether it is possible to fill all the
        // positions to the left of index while satisfying the array conditions.
        if (value - p < 2LL * index) {
            // Maximum predecessor = value-p
            // Minimum required predecessor = 2 * index
            return -1;
            // 2LL means the number 2 is treated as a long long.
            // Since index can be as large as 10^9, using 2LL * index ensures the multiplication is performed using 64-bit arithmetic.
        }

        // Calculate the number of elements on the right
        int right = n - index - 1;

        // If there are no elements on the right
        if (right == 0) {
            return value;
        }

        // Calculate the minimum possible maximum value
        // Why right = n - index - 1?
        // - It calculates how many positions are present after index.
        // Why value + p?
        // - The first element after value must be at least value + p.
        // Why 2 * (right - 1)? 
        // - Every adjacent element must differ by at least 2.
        return 1LL * value + p + 2LL * (right - 1);

        // Time Complexity: O(\sqrt{value})
        // for finding the smallest prime factor.

        // Space Complexity: O(1)
        // no extra data structures used.
    }
};