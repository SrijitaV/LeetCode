class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //                       code by ME
        // int ans = 1;
        // if (nums.empty())
        //     return 0;
        // int i = 0, j = 1;
        // while (j < nums.size()) {
        //     if (nums[i] == nums[j]) {
        //         j++;
        //     } else {
        //         i++;
        //         nums[i] = nums[j];
        //         ans++;
        //         j++;
        //     }
        // }
        // return ans;
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        //                        quite optimized approach
        if (nums.empty())
            return 0; // If the array is empty, return 0.

        // Use two pointers, i and j. Pointer i tracks the position of the last
        // unique element, while j traverses the array from index 1.
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            // Since the array is sorted, duplicates appear next to each other.
            if (nums[i] != nums[j]) { // Whenever nums[i] != nums[j], a new
                                      // unique element is found.
                i++;
                nums[i] = nums[j];
                // Increment i and copy nums[j] to nums[i].
            }
        }
        // Finally, return i + 1, which represents the number of unique
        // elements.
        return (i + 1);
        // Time Complexity: O(n)
        // Space Complexity: O(1)
    }
};