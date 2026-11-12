class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // -------------------------------------------------

        // ------------------ brute force ------------------

        int max_length = 0;

        for (int i = 0; i < nums.size(); i++) {
            int curr_length = 1;

            for (int pos = i + 1; pos < nums.size(); pos++) {
                if (nums[pos] > nums[pos - 1]) {
                    curr_length++;
                } else {
                    break;
                }
            }
            max_length = max(max_length, curr_length);
        }

        for (int i = 0; i < nums.size(); i++) {
            int curr_length = 1;

            for (int pos = i + 1; pos < nums.size(); pos++) {
                if (nums[pos] < nums[pos - 1]) {
                    curr_length++;
                } else {
                    break;
                }
            }
            max_length = max(max_length, curr_length);
        }

        return max_length;
    }
};