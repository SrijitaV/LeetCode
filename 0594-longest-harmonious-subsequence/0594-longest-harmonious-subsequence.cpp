class Solution {
public:
    int findLHS(vector<int>& nums) {

        // sort the array so, that similar and consecutive elements come
        // together
        sort(nums.begin(), nums.end());

        int i = 0;   // Left pointer
        int ans = 0; // Store maximum length

        // j is the right pointer
        for (int j = 0; j < nums.size(); j++) {

            // If difference becomes greater than 1, move i forward until difference becomes <= 1
            while (nums[j] - nums[i] > 1) {
                i++;
            }

            // If difference is exactly 1, then this is a valid harmonious subsequence
            if (nums[j] - nums[i] == 1) {
                // Current window length = j - i + 1
                ans = max(ans, j - i + 1);
            }
        }

        // result subsequence will always have two numbers only - min and min + 1
        // Return the maximum length found
        return ans;

        // Time Complexity : O(n log n), Space Complexity : O(1)
    }
};