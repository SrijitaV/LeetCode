class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Answer = sum(nums) - (n * min(nums))

        int n = nums.size();

        int sum = 0;

        int min_nums = *min_element(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }

        int ans;

        ans = sum - (n * min_nums);

        return ans;
    }
};