class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {

        // ---------- simple idea approach ---------------
        // If any number occurs more than 2 times, answer is immediately false

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // If the same element occurs 3 times
            if (i + 2 < nums.size() &&
                nums[i] == nums[i + 1] &&
                nums[i] == nums[i + 2]) {
                return false;
            }
        }

        return true;


        
        // ---------------- brute force approach by me -----------------

        // nums ka length aaadha kar k le re taaki nums1 aur nums2 banae 
        // int n = nums.size() / 2; 
        // dono arrays banae 
        // vector<int> nums1(n);
        // vector<int> nums2(n);

        // just in case unsorted array aaaya toh ham pehele sort kar lete hai 
        // sort(nums.begin(), nums.end());
        // apan poora given nums array iterate karenge so that usse doo nums1 aur nums2 form kar sake 
        // int i = 0, j = 0, k = 0; 
        // For every nums[i]:
        // while (i != nums.size()) {

            // Check whether nums[i] already exists in nums1
            // bool foundInNums1 = false;

            // for (int x = 0; x < j; x++) {
            //     if (nums1[x] == nums[i]) {
            //         foundInNums1 = true;
            //         break;
            //     }
            // }

            // Check whether nums[i] already exists in nums2
            // bool foundInNums2 = false;

            // for (int x = 0; x < k; x++) {
            //     if (nums2[x] == nums[i]) {
            //         foundInNums2 = true;
            //         break;
            //     }
            // }

            // If not present in nums1, put it there
            // if (!foundInNums1 && j < n) {
            //     nums1[j] = nums[i];
            //     j++;
            // }

            // Otherwise put it in nums2
            // else if (!foundInNums2 && k < n) {
            //     nums2[k] = nums[i];
            //     k++;
            // }

            // Already present in both
        //     else {
        //         return false;
        //     }

        //     i++;
        // }

        // return true;

        // check karenge ki nums1 mrin ya num2 mein similar items toh nahi hai , agar poore dono mein distinct elements hue toh tru varna agar kuch ek bhi similar aagya don mein se kisi mein bhi toh false 

    }
};