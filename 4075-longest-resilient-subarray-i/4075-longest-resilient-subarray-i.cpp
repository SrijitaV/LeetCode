class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {

        // https://www.youtube.com/watch?v=TptBztS5h3w

        //         Intuition / Approach
        // 1. We need to find the longest valid continuous subarray.
        // 2. We start by assuming that every individual element is a valid
        // subarray, so ans = 1.
        // 3. We maintain len to track the length of the current continuous
        // subarray we are building.
        // 4. We compare the remainder of the current element with the previous
        // element using % k.
        //    - If both remainders are equal, we can extend our current
        //    subarray.
        //    - Otherwise, we reset our subarray and start a new one from the
        //    current element.
        // 5. Along with length, we maintain sum to calculate the sum of
        // remainders modulo k.
        // 6. We update our answer when:
        //    - len == 1, because a single-element subarray is always valid.
        //    - sum == nums[i] % k, which satisfies the required condition for
        //    the current subarray.
        // 7. Finally, return the maximum length obtained.

        int n = nums.size();

        // ans stores the maximum length of a valid subarray
        // Every single element is always a valid subarray
        int ans = 1;

        // len stores the length of the current continuous subarray
        int len = 1;

        // sum stores the sum of remainders modulo k
        // Initially, we consider the first element
        int sum = nums[0] % k;

        // Start from index 1 because index 0 is already considered
        for (int i = 1; i < n; i++) {

            // Check if the current element and previous element
            // have the same remainder when divided by k
            if (nums[i] % k == nums[i - 1] % k) {

                // Same remainder, so extend the current subarray
                len++;

                // Update the sum of remainders modulo k
                sum = (sum + nums[i] % k) % k;
            } else {

                // Different remainder, so start a new subarray
                // from the current element
                len = 1;

                // Reset sum with the current element's remainder
                sum = nums[i] % k;
            }

            // A single-element subarray is always valid
            // OR
            // If sum of remainders equals the current remainder,
            // the current subarray satisfies the required condition
            if (len == 1 || sum == nums[i] % k) {

                // Update the maximum valid subarray length
                ans = max(ans, len);
            }
        }

        // Return the maximum length of a valid subarray
        return ans;

        // ------------------------------------------------------

        // auto temp_num = nums;
        // int ans = 1;
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {

        //     int sum = 0;
        //     int rem = nums[i] % k;
        //     bool valid = true;

        //     for (int j = i; j < n; j++) {

        //         sum = sum + nums[j];

        //         if (nums[j] % k != rem) {
        //             valid = false;
        //         }

        //         if (valid && sum % k == rem) {
        //             ans = max(ans, j - i + 1);
        //         }
        //     }
        // }

        // return ans;
    }
};