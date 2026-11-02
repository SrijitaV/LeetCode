class Solution {
public:
    int maxSubArray(vector<int>& nums) {

int n = nums.size();

        // Stores the sum of the current subarray
        int sum = 0;

        // Stores the maximum sum found so far
        // Initialize with nums[0] because all elements can be negative
        int result = nums[0];

        for (int i = 0; i < n; i++) {

            // If the current sum becomes negative,
            // discard the previous subarray and start fresh
            if (sum < 0) {
                sum = 0;
            }

            // Add the current element to the subarray
            sum = sum + nums[i];

            // Update the maximum subarray sum
            result = max(result, sum);
        }

        return result;
    }
};