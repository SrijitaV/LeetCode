class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto i = freq.begin(); i != freq.end(); i++) {
            if (i->second == 1)
                ans.push_back(i->first);
        }
        return ans;
    }
};