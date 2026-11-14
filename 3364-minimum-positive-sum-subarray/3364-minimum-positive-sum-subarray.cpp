
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        // ---------------- optimal solution - using prefix sum ----------------

        int n = nums.size();
        int ans = -1;

        // Iterate through all possible window sizes
        for (int size = l; size <= r; size++) {

            // Calculate sum of the first window
            int sum = 0;

            for (int j = 0; j < size; j++) {
                sum += nums[j];
            }

            // Check if the first window has a positive sum
            if (sum > 0) {
                if (ans == -1 || sum < ans) {
                    ans = sum;
                }
            }

            // Slide the window through the remaining array
            for (int i = 1; i <= n - size; i++) {

                // Remove the element leaving the window
                // Add the new element entering the window
                sum = sum - nums[i - 1] + nums[i + size - 1];

                // Update minimum positive sum
                if (sum > 0) {
                    if (ans == -1 || sum < ans) {
                        ans = sum;
                    }
                }
            }
        }

        return ans;

        // Time Complexity ~ O(n²)
        // - Outer loop O(n)
        // - inner sliding loop O(n)

        // Space Complexity ~ O(1)
        // - Only variables use ho rahe hain, no extra data structure

        // ----------------------------------------------------------------------

        // // ---------------------- my brute ofrce appraoch ----------------------

        // // Stores the minimum positive subarray sum found so far.
        // // Initially -1 means that no valid positive sum has been found.
        // int ans = -1;

        // // Stores the total number of elements in the given array.
        // int n = nums.size();

        // // Outer loop: Checks every possible window size
        // // starting from l and going up to r (both inclusive).
        // for (int size = l; size <= r; size++) {

        //     // Middle loop: Iterates through all possible starting
        //     // indices for the current window size.
        //     // n - size is the last valid starting index,
        //     // so that the window does not go out of array bounds.
        //     for (int i = 0; i <= n - size; i++) {

        //         // Stores the sum of the current subarray.
        //         // Reset to 0 for every new starting index.
        //         int sum = 0;

        //         // Inner loop: Calculates the sum of the current window.
        //         // Starts from index i and goes up to i + size - 1.
        //         for (int j = i; j < i + size; j++) {
        //             sum += nums[j];
        //         }

        //         // A subarray is considered valid only if its sum is
        //         positive. if (sum > 0) {

        //             // If this is the first positive sum found,
        //             // OR the current sum is smaller than the previous
        //             answer,
        //             // update the minimum sum.
        //             if (ans == -1 || sum < ans) {
        //                 ans = sum;
        //             }
        //         }
        //     }
        // }

        // // Returns the minimum positive sum.
        // // Returns -1 if no valid positive-sum subarray exists.
        // return ans;

        // // Time Complexity: O(n^3)
        // // - We have 3 nested loops:
        // //     1. Outer loop (size): Maximum O(n)
        // //     2. Middle loop (i): Maximum O(n)
        // //     3. Inner loop (j): Maximum O(n)
        // // -Therefore : O(n * n *s n) = O(n^3)

        // // Space Complexity: O(1)
        // // - We are using only a few variables:
        // // - ans, n, size, i, j, sum
        // // - No extra array, vector, or data structure is created.
        // // - Therefore : O(1)
    }
};
