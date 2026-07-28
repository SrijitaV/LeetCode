class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times = nums.size() / 3;
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int x : nums) {
            freq[x]++;
        }
        for (auto& p : freq) {
            if (p.second > times) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};