class Solution {
public:
    int search(vector<int>& nums, int target) {

        // ye low or high humari current search range ko maintain karenge
        int low = 0, high = nums.size() - 1;

        // jab tak search range empty nahi hoti, tab tak search karenge
        while (low <= high) {

            // ye current search range ka middle index hai
            int mid = low + (high - low) / 2;

            // agar target mid pe mil gaya toh uska index return kar denge
            if (nums[mid] == target) {
                return mid;
            }

            // check karenge ki left half sorted hai ya nahi
            if (nums[low] <= nums[mid]) {

                // left half sorted hai
                // check karenge ki target is sorted range ke andar hai ya nahi
                if (nums[low] <= target && target < nums[mid]) {

                    // target left half mein ho sakta hai
                    // isliye mid ke right wale saare elements hata denge
                    high = mid - 1;

                } else {

                    // target left half mein nahi hai
                    // isliye right half mein search karenge
                    low = mid + 1;
                }

            } else {

                // agar left half sorted nahi hai toh right half sorted hoga
                // check karenge ki target right half ke andar hai ya nahi
                if (nums[mid] < target && target <= nums[high]) {

                    // target right half mein ho sakta hai
                    // isliye left half ko eliminate kar denge
                    low = mid + 1;

                } else {

                    // target right half mein nahi hai
                    // isliye left half mein search karenge
                    high = mid - 1;
                }
            }
        }

        // agar poori search ke baad bhi target nahi mila toh -1 return karenge
        return -1;

        // Time complexity: O(log n)
        // Space complexity: O(1)
    }
};