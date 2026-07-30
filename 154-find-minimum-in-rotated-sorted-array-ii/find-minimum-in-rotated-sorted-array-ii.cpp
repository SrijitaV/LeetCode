class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])              // minimum is in the right half 
                low = mid + 1;              
            else if (nums[mid] < nums[high])       // minimum is in the left half (including mid)
                high = mid;    
            else                                  // muns[mid] == nums[high], can't determine side due to duplicates 
                high--;
        }
        return nums[low];
    }
};