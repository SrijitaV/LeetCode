class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        // ------ optimal solution ------
        int c1 = 0; // number of elements less than target
        int c2 = 0; // number of elements equal to target
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                c1++;
            } else if (nums[i] == target) {
                c2++;
            }
        }
        vector<int> ans; // array of indices
        for (int i = c1; i < (c1 + c2); i++) {
            ans.push_back(i);
        }
        return ans;

        // ------ my brute force solution ------
        // sort(nums.begin(), nums.end());
        // vector<int> ans;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == target) {
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        // Time Complexity: O(n logn) ~ because sorting takes O(n logn) and the
        // loop takes O(n). Space Complexity: O(n) ~ due to the ans vector in
        // the worst case and the auxiliary space used by sort().
    }
};