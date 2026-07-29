class Solution {
public:
    int findMin(vector<int>& nums) {
        //             TC - O(logn)
        int last = nums.back();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= last)
                return nums[i];
        }
        return -1;


        //             TC - O(n)
        // int i = 0;
        // while (i != nums.size())
        // {
        //     if (nums[i] > nums[nums.size() - 1])
        //         i++;
        //     else
        //         return nums[i];
        // }
        // return -1; 
    }
};