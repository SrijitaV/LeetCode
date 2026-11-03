class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        // left sum array bana ri
        int left_sum = 0;
        vector<int> left(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            left[i] = left_sum;
            left_sum = left_sum + nums[i];
        }

        // right sum array bana ri
        int right_sum = 0;
        vector<int> right(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            right[i] = right_sum;
            right_sum = right_sum + nums[i];
        }

        // answer array bana re
        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = abs(left[i] - right[i]);
        }

        return answer; 
    }
};