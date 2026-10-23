class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        // To swap two numbers a and b, their bitwise AND must be equal to k.
        // We need to maximize the value of k.

        int k = INT_MAX; // result

        for (int i = 0; i < nums.size(); i++) {

            // Since nums contains elements from 0 to n-1 and the array size is
            // n, at every index i, nums[i] should ideally contain i.

            // If nums[i] != i, then the element is at the wrong position.
            // This means it needs to move somewhere else to reach its correct
            // position.

            // If an element is at the wrong position, it must participate in
            // at least one swap with some other element to reach its correct
            // position.

            if (nums[i] != i) {

                // All misplaced elements must be able to participate in valid
                // swaps. Therefore, every misplaced element must have all the
                // set bits of k. Taking the cumulative AND of all misplaced
                // elements gives the maximum possible value of k.
                k = k & nums[i];
            }
        }

        // If no elements are misplaced, the permutation is already sorted.
        // In that case, the answer is 0.
        return k == INT_MAX ? 0 : k;
    }

    // Time complexity: O(n).
    // We only need to traverse the array once, performing constant-time checks
    // and bitwise operations for each element.

    // Space complexity: O(1).
    // Only a constant amount of extra space is used.
};