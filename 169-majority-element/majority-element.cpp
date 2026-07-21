class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums)
            freq[x]++;
        int ans = nums[0];
        for (auto &p : freq)
        {
            if (p.second > freq[ans])
                ans = p.first; 
        }
        return ans;
    }
};