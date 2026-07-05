class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> range(nums.size());
        int maxrange = -1; 
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int maxdigit = 0;   
            int mindigit = 9;
            while (x > 0) 
            {
                int digit = x % 10;
                x /= 10;

                if (digit > maxdigit)
                    maxdigit = digit;

                if (digit < mindigit)
                    mindigit = digit;
            }
            int digitrange = maxdigit - mindigit;   

            range[i] = digitrange;                 

            if (digitrange > maxrange)             
                maxrange = digitrange;
        }
        int ans = 0; 
        for(int k = 0; k < nums.size(); k++)
        {
            if(range[k] == maxrange)
                ans += nums[k];
        }
        return ans;
    }
};