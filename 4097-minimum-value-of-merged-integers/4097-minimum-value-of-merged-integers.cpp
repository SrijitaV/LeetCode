    class Solution {
    public:
        int minMergedInteger(vector<int>& nums) {

            int n = nums.size();

            int result = INT_MAX;

            for (int i = 0; i < n - 1; i += 2) {

                string first = to_string(nums[i]);
                string second = to_string(nums[i + 1]);

                string number = first + second;

                int ans = stoi(number);

                result = min(result, ans);
            }

            return result;
        }
    };