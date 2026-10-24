class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // ------------------ my brute force approach ---------------------

        if (nums.size() == 1) {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }

        return nums.back();

        // Time Complexity: O(n log n)
        // - if(nums.size() == 1) takes O(1).
        // - sort(nums.begin(), nums.end()) takes O(n log n).
        // - The for loop traverses the array in steps of 2, taking O(n).
        // - nums.back() takes O(1).
        // Overall, sorting dominates, so TC = O(n log n).

        // Space Complexity: O(log n)
        // - The loop uses O(1) extra space.
        // - std::sort() typically uses O(log n) auxiliary stack space due to
        // recursion in its introsort implementation.
    }
};