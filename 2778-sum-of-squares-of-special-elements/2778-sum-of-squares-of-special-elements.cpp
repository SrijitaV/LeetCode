class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        // ---------- my brute force appraoch ------------
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = i + 1;
            if ((nums.size() % temp) == 0)
            {
                ans = ans + (nums[i] * nums[i]); 
            }
        }
        return ans; 
    }
};