
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        // ----------- optimal solution (prefix sum) ------------

        // --- Intuition ---

        // We solve this problem using two traversals.
        // In the first traversal, we iterate through the array from left to
        // right while maintaining a variable leftSum,
        // which represents the sum of all elements to the left of the current
        // position We store this value in ans[i], and then add nums[i] to
        // leftSum.

        // In the second traversal,
        // we iterate through the array from right to left while maintaining a
        // variable rightSum,
        // which represents the sum of all elements to the right of the current
        // position.At this point,
        // ans[i] already stores the sum of all elements to the left of position
        // i, so we update ans[i] to ∣ans[i]−rightSum∣.Then, we add nums[i] to
        // rightSum.

        int n = nums.size();
        vector<int> ans(n);

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;

        // Time complexity: O(n)

        // Space complexity: O(1) ~ The space occupied by the return value is
        // not included.

        // ----------------------------------------------------------

        // ---------------- brute force approch ----------------

        // left sum array bana ri
        // int left_sum = 0;
        // vector<int> left(nums.size());

        // for (int i = 0; i < nums.size(); i++) {

        //     // current index k left m jitne elements h unka sum store karega
        //     left[i] = left_sum;

        //     // next index k liye left sum update karega
        //     left_sum = left_sum + nums[i];
        // }

        // // right sum array bana ri
        // int right_sum = 0;
        // vector<int> right(nums.size());

        // for (int i = nums.size() - 1; i >= 0; i--) {

        //     // current index k right m jitne elements h unka sum store karega
        //     right[i] = right_sum;

        //     // next index k liye right sum update karega
        //     right_sum = right_sum + nums[i];
        // }

        // // answer array bana re
        // vector<int> answer(nums.size());

        // for (int i = 0; i < nums.size(); i++) {

        //     // left aur right sum ka absolute difference store karega
        //     answer[i] = abs(left[i] - right[i]);
        // }

        // return answer;

        //         Time Complexity: O(n)
        // - We traverse the input array three times.
        // - Therefore: O(n) + O(n) + O(n) = O(3n) = O(n)

        // Space Complexity: O(n)
        // - We create three additional vectors: left → O(n), right → O(n),
        // answer → O(n) Total auxiliary space: O(3n) = O(n)
    }
};
