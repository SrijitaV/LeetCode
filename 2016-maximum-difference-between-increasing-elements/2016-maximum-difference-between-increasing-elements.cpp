class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int mini = nums[0]; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mini) {
                ans = max(ans, nums[i] - mini);
            }
            mini = min(mini, nums[i]);
        }

        return ans;
    }
};