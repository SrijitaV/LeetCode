class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        // --------------- two pointer appraoch --------------

        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // i starts from the beginning and j from the end
        int i = 0, j = nums.size() - 1;
        int count = 0;

        // Run the loop until both pointers meet
        while (i < j) {

            // Check if the sum of both elements is less than target
            if (nums[i] + nums[j] < target) {

                // All elements from i+1 to j form valid pairs with nums[i]
                count = count + j - i;

                // If the smallest element plus the largest element is still
                // less than the target, every element between them forms a
                // valid pair with the smallest element.

                // Move i forward to check the next element
                i++;

            } else {

                // Sum is too large, so move j backward
                j--;
            }
        }

        // Return the total number of valid pairs
        return count;

        // Time Complexity : O(n log n)
        // Space Complexity : O(log n)

        // --------------- my brute force approach -------------
        // int count = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if ((nums[i] + nums[j]) < target) {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        // Time Complexity : O(n^2)
        // Space Complexity : O(1)
    }
};