
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        // left sum array bana ri
        int left_sum = 0;
        vector<int> left(nums.size());

        for (int i = 0; i < nums.size(); i++) {

            // current index k left m jitne elements h unka sum store karega
            left[i] = left_sum;

            // next index k liye left sum update karega
            left_sum = left_sum + nums[i];
        }

        // right sum array bana ri
        int right_sum = 0;
        vector<int> right(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {

            // current index k right m jitne elements h unka sum store karega
            right[i] = right_sum;

            // next index k liye right sum update karega
            right_sum = right_sum + nums[i];
        }

        // answer array bana re
        vector<int> answer(nums.size());

        for (int i = 0; i < nums.size(); i++) {

            // left aur right sum ka absolute difference store karega
            answer[i] = abs(left[i] - right[i]);
        }

        return answer;

        //         Time Complexity: O(n)
        // - We traverse the input array three times.
        // - Therefore: O(n) + O(n) + O(n) = O(3n) = O(n)

        // Space Complexity: O(n)
        // - We create three additional vectors: left → O(n), right → O(n),
        // answer → O(n) Total auxiliary space: O(3n) = O(n)
    }
};
