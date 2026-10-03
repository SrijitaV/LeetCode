class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // To find the contiguous subarray of length k with the maximum average, we can use the sliding window technique. Instead of recalculating the sum for every subarray, we maintain a running sum of size k, updating it by subtracting the element leaving the window and adding the new element entering the window. This efficiently tracks the maximum sum.

        int sum = 0; 

        for (int i = 0; i < k; i++)
        {
            sum = sum + nums[i];
        }

        int maxsum = sum; 

        for (int i = k; i < nums.size(); i++)
        {
            sum = sum - nums[i - k] + nums[i];
            maxsum = max(maxsum, sum);
        }

        return (double) maxsum / k;

        // Time complexity: O(n) → Single pass through the array using the sliding window.
        // Space complexity: O(1) → Only a few variables are used; no extra data structures.


        // --------------- TLE aagya -----------------

        // double ans = INT_MIN;

        // int i = 0, j = k - 1;

        // while (j < nums.size()) {
        //     long long sum = 0;

        //     for (int x = i; x <= j; x++) {
        //         sum = sum + nums[x];
        //     }

        //     double average = (double)sum / k;

        //     ans = max(ans, average);

        //     i++;
        //     j++;
        // }

        // return ans;

        // Time: O(n)
        // Space: O(1)
    }
};