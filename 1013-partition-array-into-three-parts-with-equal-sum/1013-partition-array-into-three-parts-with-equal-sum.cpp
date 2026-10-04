class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {

        // Find the total sum of the array
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum = sum + arr[i];
        }

        // If total sum is not divisible by 3,
        // we cannot divide the array into 3 equal-sum parts
        if (sum % 3 != 0) {
            return false;
        }

        // Each of the 3 parts should have this sum
        sum = sum / 3;

        // curr -> stores the sum of current part
        // ans -> counts how many parts with required sum we have found
        int curr = 0, ans = 0;

        for (int i = 0; i < arr.size(); i++) {

            // Add current element to current part's sum
            curr = curr + arr[i];

            // If current part has reached the required sum
            if (curr == sum) {

                // Start finding the next part
                curr = 0;

                // One equal-sum part is completed
                ans = ans + 1;
            }

            // If we have found all 3 parts
            if (ans == 3) {
                return true;
            }
        }

        // If we could not find 3 equal-sum parts
        return false;

        // Time: O(n) because we traverse the array twice.
        // Space: O(1) because we only use sum, curr, and ans.
    }
};