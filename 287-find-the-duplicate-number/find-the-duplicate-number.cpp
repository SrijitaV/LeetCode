class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //                                       brute force approach 
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == nums[i + 1])
        //         return nums[i];
        // }
        // return 0;
        //                                        TC = O(n logn)
        //                                        SC = O(n)
//  -----------------------------------------------------------------------------
        //                                       negative flag 
        // for (int i = 0; i < nums.size(); i++) {

        //     int index = abs(nums[i]);

        //     if (nums[index] < 0) {
        //         return index;
        //     }

        //     nums[index] *= -1;
        // }
        // return -1;
        //                                          TC = O(n)
        //                                          SC = O(1)
//  -----------------------------------------------------------------------------
        //                                        map
        map<int, int> mapp;
        for(int i = 0; i < nums.size(); i++)
        {
            mapp[nums[i]]++;
        }
        for(auto it : mapp)
        {
            if(it.second == 1)
                continue; 
            return it.first; 
        }
        return 0; 
        //                                            TC = O((n * logm) + m)  =>   m is ((n / 2) + 1)
        //                                            SC = O(m)
//  -----------------------------------------------------------------------------
        //                                        bit manipulation 
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i]; 
        } 
        return ans; 
//  -----------------------------------------------------------------------------

    }
};