class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // nums ko sort karenge taki median easily find kar sake
        sort(nums.begin(), nums.end());

        // ye mid index find karega
        int mid = nums.size() / 2;

        // sorted array ka middle element target hoga
        int target = nums[mid];

        // ye total moves store karega
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            // har element ko target ke equal karne ke liye
            // kitne moves lagenge wo calculate karenge
            int move = abs(target - nums[i]);

            // total moves mein current element ke moves add karenge
            ans = ans + move;
        }

        return ans;

        // Time Complexity (TC) ~ (n log n)
        // - Sorting the array takes O(n log n).
        // - Finding the median takes O(1).
        // - Traversing the array to calculate moves takes O(n).
        // Therefore: O(n logn) + O(1) + O(n) = O(n logn)

        // Space Complexity (SC) ~ O(log n)
        // - auxiliary space for sorting in typical C++ implementations
        // - using std::sort (implementation-dependent stack space).
    }
};