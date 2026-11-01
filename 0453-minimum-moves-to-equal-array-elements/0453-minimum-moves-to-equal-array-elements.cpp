class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Answer = sum(nums) - (n * min(nums))

        // --------------- optimized brute force appraoch -----------------
        int n = nums.size();
        int sum = 0;
        int min_nums = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            min_nums = min(min_nums, nums[i]);
        }
        int ans = sum - (n * min_nums);
        return ans;
        // Time Complexity ~ O(n)
        // Space Complexity ~ O(1)

        // ------------------ my brute force approach -----------------
        // int n = nums.size();
        // int sum = 0;
        // int min_nums = *min_element(nums.begin(), nums.end());
        // for (int i = 0; i < n; i++) {
        //     sum = sum + nums[i];
        // }
        // int ans;
        // ans = sum - (n * min_nums);
        // return ans;
        // Time Complexity ~ O(n)
        // Space Complexity ~ O(1)
    }
};