class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // sort(nums.begin(), nums.end(), greater<int>());
        // vector<int> temp(nums.size());
        // int even = 0, odd = 1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (i % 2 == 0) {
        //         temp[even] = nums[i];
        //         even++;
        //     } else {
        //         temp[odd] = nums[i];
        //         odd++;
        //     }
        // }

        // long long ans = 0;
        // for (int i = 0; i < temp.size(); i++) {
        //     long long square = 1LL * temp[i] * temp[i];
        //     if (i % 2 == 0) {
        //         ans = ans + square;
        //     } else {
        //         ans = ans - square;
        //     }
        // }
        // return ans;

        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) > abs(b); });
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];

            if (i < (n + 1) / 2) {
                ans = ans + square;
            } else {
                ans = ans - square;
            }
        }
        return ans;

        // Time Complexity: O(n log n) 
        //     sort(nums.begin(), nums.end(), ...) takes - O(n log n)
        //     the for loop iterates through all \(n\) elements taking - O(n)
        //     the total is - O(n log n)
        //     note: the sorting modifies nums in place, so you don't create another array.
        // Space Complexity: O(log n) ~ auxiliary space on average for std::sort (implementation-dependent stack usage)
    }
};