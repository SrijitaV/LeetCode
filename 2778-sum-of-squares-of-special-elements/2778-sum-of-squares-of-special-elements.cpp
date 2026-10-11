class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        // ---------- my brute force appraoch ------------
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums.size() % (i + 1)) == 0) {
                ans = ans + (nums[i] * nums[i]);
            }
        }
        return ans;
        // Time: O(n)
        // Space: O(1)
    }
};