class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        while (i != nums.size())
        {
            if (nums[i] > nums[nums.size() - 1])
                i++;
            else
                return nums[i];
        }
        return -1; 
    }
};