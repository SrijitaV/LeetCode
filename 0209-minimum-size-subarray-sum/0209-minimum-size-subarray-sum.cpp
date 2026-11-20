
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = 0;  // window ke starting aur ending index
        int sum = 0;              // current window ka sum
        int ans = INT_MAX;        // minimum subarray length store karega

        while (right < n) {
            sum = sum + nums[right];  // right wale element ko window me add kar rahe

            while (sum >= target) {   // jab tak current sum target se bada ya equal h

                ans = min(ans, right - left + 1);  // minimum window length update kar rahe

                sum = sum - nums[left];  // left wala element window se remove kar rahe
                left++;                  // window ka starting index aage badha rahe
            }

            right++;  // window ka ending index aage badha rahe
        }

        if (ans == INT_MAX) {
            return 0;  // agar koi valid subarray nahi mila
        }

        return ans;  // minimum subarray length return kar rahe
    }
};
