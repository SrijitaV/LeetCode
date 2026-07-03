class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int right = nums.size() - 1; right > 0; right--) {
            for (int left = 0; left < right; left++) {
                if (nums[left] > nums[left + 1]) {
                    swap(nums[left], nums[left + 1]);
                }
            }
        }
    }
};