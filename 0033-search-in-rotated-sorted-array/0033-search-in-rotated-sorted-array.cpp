class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                // Left half is sorted

                if (nums[low] <= target && target < nums[mid]) {
                    // Target is in the left half
                    high = mid - 1;
                } else {
                    // Target is in the right half
                    low = mid + 1;
                }

            } else {
                // Right half is sorted

                if (nums[mid] < target && target <= nums[high]) {
                    // Target is in the right half
                    low = mid + 1;
                } else {
                    // Target is in the left half
                    high = mid - 1;
                }
            }
        }
        return -1;

        // Time complexity: O(log n)
        // Space complexity: O(1)
    }
};