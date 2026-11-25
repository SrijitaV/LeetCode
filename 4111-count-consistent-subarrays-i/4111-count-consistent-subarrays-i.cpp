class Solution {
public:
    int countConsistent(vector<int>& nums) {

        // INTUITION:

        // 1. We need to count all subarrays where the bitwise AND
        //    of all elements is equal to the minimum element.

        // 2. We generate all possible subarrays using two loops:
        //    - i represents the starting index.
        //    - j represents the ending index.

        // 3. For every new subarray, we maintain two variables:

        //    mini = minimum element in the current subarray.
        //    bit  = bitwise AND of all elements in the current subarray.

        // 4. As we extend the subarray by moving j:
        //    - Update mini using min().
        //    - Update bit using bitwise AND (&).

        // 5. If bit == mini, the current subarray satisfies
        //    the given condition, so we increment count.

        // 6. Finally, return count.

        int n = nums.size();
        int count = 0;

        // traversing through all possible starting indices
        for (int i = 0; i < n; i++) {

            int mini = INT_MAX;
            int bit = INT_MAX;

            // finding all subarrays starting from index i
            for (int j = i; j < n; j++) {

                // maintaining the minimum element in the subarray
                mini = min(mini, nums[j]);

                // maintaining the bitwise AND of all elements
                bit = bit & nums[j];

                // checking if bitwise AND is equal to minimum element
                if (bit == mini) {
                    count++;
                }
            }
        }

        return count;

        // TIME COMPLEXITY: O(N^2)
        // - Outer loop runs N times.
        // - Inner loop runs up to N times.
        // - Each operation inside the loop takes O(1).
        // Therefore, TC = O(N^2).

        // SPACE COMPLEXITY: O(1)
        // - We use only a few extra variables:
        //   mini, bit, count, i and j.
        // - No additional data structure is used.
        // Therefore, SC = O(1).
    }
};
