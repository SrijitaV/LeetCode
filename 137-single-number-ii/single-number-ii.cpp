class Solution {
public:
    int singleNumber(vector<int>& nums) {
// ------------------------------------------------------------------------------------
        //                                                                         map
        // map<int, int> mapp;
        // for (int i = 0; i < nums.size(); i++)
        //     mapp[nums[i]]++;
        // for(auto it : mapp)
        // {
        //     if(it.second == 1)
        //         return it.first;
        // }
        // return 0; 
        //                                                  TC = O((n * logm) + m) + O(m)
        //                                                  SC = O(m)

    // }
// ------------------------------------------------------------------------------------
        //                                                                         counting bit position 
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            int count = 0; 
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[j] & (1 << i))
                {
                    count++;
                }
            }
            if((count % 3) == 1)
            {
                ans |= (1 << i);
            }
            
        }
        return ans;
    }
};