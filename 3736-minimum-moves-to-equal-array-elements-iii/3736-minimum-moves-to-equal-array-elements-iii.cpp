class Solution {
public:
    int minMoves(vector<int>& nums) {

        int ans = 0;

        // ye nums vector ka sabse bada element find karega
        int max_val = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // ye max_val or current nums[i] ka difference nikalega
            int temp = abs(max_val - nums[i]);

            // ye sabhi elements k difference ko add karta jayega
            ans = ans + temp;
        }

        return ans;

        //         TC: O(n)
        // - max_element() takes O(n).
        // - The for loop takes O(n).

        // SC: O(1)
        // - We use only a few extra variables, so SC is O(1)
    }
};