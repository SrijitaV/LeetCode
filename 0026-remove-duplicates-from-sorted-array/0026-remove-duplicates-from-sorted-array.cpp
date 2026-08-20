class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //                       code by ME 
        // int ans = 1;
        // if (nums.empty())
        //     return 0; 
        // int i = 0, j = 1;
        // while (j < nums.size()) {
        //     if (nums[i] == nums[j]) {
        //         j++;
        //     } else {
        //         i++;
        //         nums[i] = nums[j];
        //         ans++;
        //         j++;
        //     }
        // }
        // return ans;


        //                        quite optimized approach
        if (nums.empty())
            return 0; 
        int i = 0; 
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++; 
                nums[i] = nums[j];
            }
        }    
        return (i + 1);     
    }
};