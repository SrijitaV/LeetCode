class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        int n = nums.size();
        vector<int> target;

        if (n == 1)
            return nums;
        
        for (int i = 0; i < n; i++) {
            target.insert(target.begin() + index[i], nums[i]);
        
        }
        return target;

// Time Complexity ~ O(n²)
// - Your loop runs n times.
// - In every iteration, vector::insert() may shift existing elements to the right.
// - In the worst case, it shifts up to n-1 elements.
// - Total: n * n = O(n^2).

// Space Complexity ~ O(n)
// - target stores all n elements.
// - No additional data structure is used.
    }
};