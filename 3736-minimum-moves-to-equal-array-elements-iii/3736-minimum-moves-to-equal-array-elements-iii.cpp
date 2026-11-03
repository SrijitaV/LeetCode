class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int max_val = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int temp = abs(max_val - nums[i]);
            ans = ans + temp;
        }
        return ans;
    }
};