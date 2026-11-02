class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;

        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] == 1) {
                j++;
            } else { // j != 1

                // Calculate the length of the current sequence
                ans = max(j - i, ans);

                // Skip the zero and start a new sequence
                j++;
                i = j;
            }
        }

        // Check the last sequence
        ans = max(j - i, ans);

        return ans;

        //         Time Complexity: O(n)
        // We traverse the array using pointer j. Each element is visited
        // exactly once.

        // Space Complexity: O(1)
        // We use only three extra variables: i, j, and ans. No additional data
        // structures.
    }
};