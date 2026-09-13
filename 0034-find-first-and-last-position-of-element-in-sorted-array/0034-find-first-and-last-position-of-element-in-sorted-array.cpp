class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = -1, end = -1;
        int left = 0, right = nums.size() - 1;

        // for finding left occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                start = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // reset for second binary search
        left = 0;
        right = nums.size() - 1;

        // for finding right occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                end = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {start, end};

        // Time Complexity - O(log n) 
        // Space Complexity - O(1)

        // ------------------- Linear Search -------------------
        // int start = -1, end = -1;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == target)
        //     {
        //         start = i - 1;
        //         for (int j = i + 1; j < nums.size(); j++)
        //         {
        //             if (nums[j] != target)
        //             {
        //                 end = j - 1;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return {start, end};
        
        // Time Complexity:  O(n)
        // Space Complexity: O(1)

    }
};