class Solution {
public:
    int singleNumber(vector<int>& nums) {

// ------------------------------------------------------------------------------------
        //                                                                         map
        map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++)
            mapp[nums[i]]++;
        for(auto it : mapp)
        {
            if(it.second == 1)
                return it.first;
        }
        return 0; 
    }
};