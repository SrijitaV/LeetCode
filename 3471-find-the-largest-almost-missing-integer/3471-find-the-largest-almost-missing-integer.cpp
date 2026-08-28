class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        //         When k=n:
        // The entire array is exactly one sliding window. Therefore, every
        // number in the array appears in a subarray of size k. To find the
        // largest nearly missing integer, we simply return the maximum value in
        // the array.
        if (n == k) {
            return *max_element(nums.begin(), nums.end());
        }

        //         When k=1:
        // The length of each sliding window is 1. Therefore, the problem asks
        // us to find the largest number that appears exactly once in the entire
        // array. After counting the frequency of each number, we traverse the
        // possible values from largest to smallest. The first number whose
        // frequency is 1 is the largest answer.
        int count[51] = {0};
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        if (k == 1) {
            for (int i = 50; i >= 0; --i) {
                if (count[i] == 1) {
                    return i;
                }
            }
            return -1;
        }

        // When 1<k<n:
        // Every element except the first and last elements of the array is
        // covered by at least two sliding windows. Therefore, no middle element
        // can satisfy the requirement. The only possible candidates are the
        // first and last elements of the array. We only need to check whether
        // these two elements appear exactly once in the entire array. If either
        // element satisfies the condition, we return the larger one among them.
        // If neither satisfies the condition, we return −1.
        int ans = -1;
        if (count[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (count[nums.back()] == 1) {
            ans = max(ans, nums.back());
        }
        return ans;
    }
};