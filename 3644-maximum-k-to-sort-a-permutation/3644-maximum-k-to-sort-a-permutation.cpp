class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        // First, consider a key property: if two numbers a and b satisfy a&b=k, every set bit of k must also be set in both a and b. In other words, the set bits of k must be a subset of the set bits in both a and b, which implies a&k=k and b&k=k.

        int k = INT_MAX; // result

        for (int i = 0; i < nums.size(); i++) {
            
            // We ultimately need to transform the permutation nums into [0,1,2,…,n−1]. Elements already in their correct positions, where nums[i]=i, do not need to participate in any swaps. Every misplaced element must reach its correct position through swaps.

            // Every misplaced element nums[i] (where nums[i] != i) must participate in at least one swap satisfying nums[i]&nums[j]=k for some index j. Therefore, it must satisfy nums[i]&k=k, meaning that every set bit of k must be present in all misplaced elements.

            // solution hoga galat jagah walo ka cumulative AND

            if (nums[i] != i)
            {
                k = k & nums[i];
            }
            else 
            {
                continue; 
            }

        }

        return k == INT_MAX ? 0 : k;
    }
};