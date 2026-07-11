class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target;
        if (n == 1)
            return nums;
        for(int i = 0; i < n; i++)
        {
            target.insert(target.begin()+index[i], nums[i]);
        }
        return target; 
    }
};