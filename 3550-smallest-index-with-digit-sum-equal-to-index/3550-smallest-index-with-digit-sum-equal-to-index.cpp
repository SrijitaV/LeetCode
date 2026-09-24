class Solution {
private: 
    int fSum(int n)
    {
        int ans = 0; 
        string s = to_string(n);
        for (int i = 0; i < s.length(); i++)
        {
            ans = ans + (s[i] - '0');
        }
        return ans; 
    }

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = fSum(nums[i]);
            if (sum == i)
            {
                return i;
            }
        }
        return -1;
    }
};