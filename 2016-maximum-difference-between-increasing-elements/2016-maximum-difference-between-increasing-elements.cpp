class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int ans = -1;

        // traversing the array
        for (int i = 1; i < nums.size(); i++) {

            // checking if current element is greater than minimum element
            if (nums[i] > mini) {
                int diff = nums[i] - mini;
                ans = max(ans, diff);
            }

            // updating the minimum element visited so far
            mini = min(mini, nums[i]);
        }

        return ans;

        // Time Complexity: O(n)
// We traverse the array only once. Each iteration takes O(1) time.

// Space Complexity: O(1)
// We use only two extra variables, mini and ans, irrespective of the array size.
    }
};