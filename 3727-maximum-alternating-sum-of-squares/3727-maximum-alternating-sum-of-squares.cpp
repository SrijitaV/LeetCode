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

        sort(nums.begin(), nums.end(), [](int a, int b)
        {
            return abs(a) > abs(b);
        });
        int n = nums.size();
        long long ans = 0; 

        for (int i = 0; i < n; i++)
        {
            long long square = 1LL * nums[i] * nums[i];

            if (i < (n + 1) / 2)
            {
                ans = ans + square;
            }
            else 
            {
                ans = ans - square; 
            }
        }
        return ans; 
    }
};