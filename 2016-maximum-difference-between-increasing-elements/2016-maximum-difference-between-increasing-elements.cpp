class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        // Intuition: Prefix Minimum

        // We need to find the maximum difference nums[j] - nums[i]
        // such that i < j and nums[i] < nums[j].

        // Instead of checking every possible pair, we can maintain
        // the minimum element encountered so far.

        // 1. Initialize mini with the first element because it is
        //    the smallest element visited so far.

        // 2. Traverse the array from index 1.

        // 3. If the current element is greater than mini,
        //    calculate the difference and update ans.

        // 4. Update mini with the minimum of mini and the current element.

        // 5. Return ans. If no valid pair exists, it remains -1.
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
        // We traverse the array only once.
        // Each iteration takes O(1) time.

        // Space Complexity: O(1)
        // We use only two extra variables,
        // mini and ans, irrespective of the array size.
    }
};