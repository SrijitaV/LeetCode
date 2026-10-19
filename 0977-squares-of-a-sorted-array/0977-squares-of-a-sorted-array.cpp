class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // two pointer approach
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        int k = n - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[k] = nums[left] * nums[left];
                left++;
            } else {
                ans[k] = nums[right] * nums[right];
                right--;
            }
            k--;
        }
        return ans;
        // Time Complexity: O(n)
        // Space Complexity: O(n)

        // my brute force appraoch
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     ans.push_back(nums[i] * nums[i]);
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
        // Time Complexity: O(n log n)
        // Space Complexity: O(n)
    }
};