class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        // ----------- better appraoch ------------

        int n = nums.size();

        // poore array ka sum le re
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total = total + nums[i];
        }

        // x ko directly subtract karne ke bajaye,
        // total - x ko target bana ke longest subarray find karenge
        int target = total - x;

        // agar target 0 hai, toh fir toh sab elements ko remove krna hoga
        if (target == 0) {
            return n;
        }

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        // longest subarray find kar rahe hain jiska sum target hai
        for (int right = 0; right < n; right++) {

            // right element add kar rahe hain
            sum += nums[right];

            // sum bada ho gaya toh left se elements remove karenge
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // target mil gaya toh maximum length update karenge
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // agar target sum ka koi subarray nahi mila
        if (maxLen == -1)
            return -1;

        // jo elements subarray ke bahar hain unko remove karna hai
        return n - maxLen;

        // Time complexity: O(n)
        //  O(n) + O(n) = O(n)
        // ek total sum ka aur ek sliding window ka

        // Space complexity: O(1)

        // ------------- brute force - trial ------------------

        // int ans = 0; // minimum number of operations required
        // int left = 0, right = nums.size() - 1;
        // while (left < right) {
        //     if (x >= nums[right]) {
        //         x = x - nums[right];
        //         right--;
        //         ans++;
        //     }
        //     if (x == 0) {
        //         return ans;
        //     }
        //     if (nums[left]) {
        //         x = x - nums[left];
        //         left++;
        //         ans++;
        //     }
        //     if (x == 0) {
        //         return ans;
        //     }
        // }
        // return -1;

        // ye wala idea fat gaya qki mai agar ek hi taraf se number subtract
        // krna hua either left or right maine vo handle hi ni kiya tha .. .so
        // the better idea approach lagay apna
    }
};