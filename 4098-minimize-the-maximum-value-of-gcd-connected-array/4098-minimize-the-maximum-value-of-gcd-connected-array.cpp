class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {

        if (value == 1) {
            return -1;
        };

        // Find the smallest prime factor of value
        int p = value;

        for (int i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        // Check whether the left side is possible
        if (value - p < 2LL * index) {
            return -1;
        }

        // Calculate the number of elements on the right
        int right = n - index - 1;

        // If there are no elements on the right
        if (right == 0) {
            return value;
        }

        // Calculate the minimum possible maximum value
        return 1LL * value + p + 2LL * (right - 1);

        // Time Complexity: O(\sqrt{value})
        // for finding the smallest prime factor.

        // Space Complexity: O(1)
        // no extra data structures used.
    }
};