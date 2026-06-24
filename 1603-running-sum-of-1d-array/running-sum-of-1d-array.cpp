class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> arr;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if(i == 0)
            {
                arr.push_back(nums[0]);
            }
            else
            {
                arr.push_back(nums[i]+arr[i-1]);
            }
        }
        return arr;
    }
};