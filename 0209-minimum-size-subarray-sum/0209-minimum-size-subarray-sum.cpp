
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // ----------------- sliding window + two pointer -----------------

        int n = nums.size();

        int left = 0, right = 0; // window ke starting aur ending index
        int sum = 0;             // current window ka sum
        int ans = INT_MAX;       // minimum subarray length store karega

        while (right < n) {
            sum = sum +
                  nums[right]; // right wale element ko window me add kar rahe

            while (sum >=
                   target) { // jab tak current sum target se bada ya equal h

                ans = min(ans, right - left +
                                   1); // minimum window length update kar rahe

                sum = sum -
                      nums[left]; // left wala element window se remove kar rahe
                left++;           // window ka starting index aage badha rahe
            }

            right++; // window ka ending index aage badha rahe
        }

        if (ans == INT_MAX) {
            return 0; // agar koi valid subarray nahi mila
        }

        return ans; // minimum subarray length return kar rahe

        // Complexity Analysis:

        // Let n = size of the input array.

        // Time Complexity: O(n)
        // - right traverses the array once, so O(n).
        // - left also traverses the array, but never moves backwards,
        // so O(n).
        // - Although there is a nested while loop, the total number of
        // iterations of both pointers is at most 2n.
        // Therefore:
        // O(n) + O(n) = O(2n) = O(n)

        // Space Complexity: O(1)
        // - Only a few variables are used: left, right, sum, ans, and n.
        // - No additional array, vector, or data structure is created.
        // Therefore:
        // O(1)

        // -----------------------------------------------------------------

        // -------- O(n log n) approach: Prefix Sum + Binary Search --------

        // int n = nums.size();

        // vector<int> prefix(n + 1, 0);

        // // prefix sum calculate kar rahe
        // for (int i = 0; i < n; i++) {
        //     prefix[i + 1] = prefix[i] + nums[i];
        // }

        // int ans = INT_MAX;

        // // har starting index ke liye binary search kar rahe
        // for (int i = 0; i < n; i++) {

        //     int required = target + prefix[i];

        //     // required sum find karne ke liye lower_bound
        //     auto it = lower_bound(prefix.begin() + i + 1,
        //                           prefix.end(), required);

        //     // agar valid ending index mil gaya
        //     if (it != prefix.end()) {
        //         int len = it - (prefix.begin() + i);
        //         ans = min(ans, len);
        //     }
        // }

        // // agar koi valid subarray nahi mila
        // if (ans == INT_MAX) {
        //     return 0;
        // }

        // return ans;

        // Complexity Analysis:

        // Let n = size of the input array.

        // Time Complexity: O(n log n)
        // - Calculating the prefix sum takes O(n).
        // - We iterate through the array once, so O(n).
        // - For every starting index, we perform binary search, which takes
        // O(log n).
        // - Therefore, binary search for all n starting indices takes O(n log
        // n).

        // Therefore:
        // O(n) + O(n log n) = O(n log n)

        // Space Complexity: O(n)
        // - An additional prefix sum array of size n + 1 is created.
        // - Other variables require O(1) space.

        // Therefore:
        // O(n)
    }
};
