class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        // given array ka size
        int n = nums.size();

        // sort kar lete hai kaam aega
        sort(nums.begin(), nums.end());

        int case1 = nums[n - 1] - nums[2];
        int case2 = nums[n - 2] - nums[1];
        int case3 = nums[n - 3] - nums[0];

        return min({case1, case2, case3});
    }
};