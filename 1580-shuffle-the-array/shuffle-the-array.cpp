class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int first = 0, second = n;
        while (second != nums.size())
        {
            ans.push_back(nums[first]);
            ans.push_back(nums[second]);
            first++, second++;
        }
        return ans;
    }
};