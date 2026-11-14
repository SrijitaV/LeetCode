class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        // ye final answer
        int ans = -1;

        // given array ka size aage use karne k liye
        int n = nums.size();

        // sabhi size ka window ko check karne k liye
        for (int size = l; size <= r; size++) {

            // given array ko iterate kar k minimum sum find out kar rahe hai
            for (int i = 0; i <= n - size; i++) {

                // temporary sum find karne k liye
                int sum = 0;

                // considered window ka sum find kar k liye
                for (int j = i; j < i + size; j++) {
                    sum = sum + nums[j];
                }

                if (sum > 0) {
                    if (ans == -1 || sum < ans) {
                        ans = sum;
                    }
                }
            }
        }

        // result return kar re
        return ans;
    }
};