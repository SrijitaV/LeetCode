class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        auto temp_num = nums;
        int ans = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int sum = 0;
            int rem = nums[i] % k;
            bool valid = true;

            for (int j = i; j < n; j++) {

                sum = sum + nums[j];

                if (nums[j] % k != rem) {
                    valid = false;
                }

                if (valid && sum % k == rem) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};