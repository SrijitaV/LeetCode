class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalxor = 0; 
        for (int i = 0; i < nums.size(); i++)
            totalxor = totalxor ^ nums[i];
        if (totalxor != 0)                   // no zero in the array 
            return nums.size(); 
        for (int i = 0; i < nums.size(); i++)       // there is zero in the array 
        {
            if (nums[i] != 0)
                return nums.size() - 1;            
        }
        return 0;
    }
};

//     XOR property 
// a ^ a = 0
// a ^ 0 = a