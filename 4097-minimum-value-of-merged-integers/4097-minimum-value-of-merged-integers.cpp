class Solution {
public:
    int minMergedInteger(vector<int>& nums) {

        int n = nums.size(); 
        // given array ka size 

        int result = INT_MAX; 
        // ye minimum merged number store karega

        for (int i = 0; i < n - 1; i += 2) {

            // i +=2 : question specifically asks you
            // to merge elements in non-overlapping pairs:
            // nums[0] with nums[1], nums[2] with nums[3], nums[4] with nums[5]

            string first = to_string(nums[i]);  
            // ye first number ke digits ko string mein convert karega

            string second = to_string(nums[i + 1]); 
            // ye second number ke digits ko string mein convert karega

            string number = first + second;
            // ye dono strings ko concatenate karega
            // first ke digits pehle aur second ke digits baad mein aayenge

            int ans = stoi(number);
            // ye concatenated string ko integer mein convert karega

            result = min(result, ans);
            // ye ab tak ke minimum merged number ko update karega
        }

        return result;
        // ye sabhi merged numbers mein se minimum return karega

        // TC: O(n) 
        // iterating given arrya once

        // SC: O(1)
        // since the temporary strings have bounded length due to the constraints.
    }
};