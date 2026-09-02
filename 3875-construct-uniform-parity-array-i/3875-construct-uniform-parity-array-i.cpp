class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
// ======== most optimized idea =======
        // return true; // iska logic ye hai ki : pehla ~ dimag kam lagao, dusra ~
                     // jab given array ko anyways odd bana hi rahai toh har
                     // case mein true hi return hoga


// ======= ideal idea for real solution =======

        // If all elements are even, keep every element as it is : nums2[i] = nums1[i].
        // Otherwise, there is at least one odd number. Pick that odd number as
        // nums1[j]. If nums1[i] is odd, keep it. If nums1[i] is even, use
        // nums1[i] - nums1[j], which becomes odd.

        //  int n = nums1.size();
        
        // // Find an odd number
        // int oddIndex = -1;
        
        // for (int i = 0; i < n; i++) {
        //     if (nums1[i] % 2 != 0) {
        //         oddIndex = i;
        //         break;
        //     }
        // }
        
        // // nums1 contains no odd number
        // // Therefore, all numbers are even
        // if (oddIndex == -1) {
        //     return true;
        // }
        
        // // There is an odd number.
        // // Try to make every element odd.
        // for (int i = 0; i < n; i++) {
            
        //     if (nums1[i] % 2 != 0) {
        //         // Keep the original odd number
        //         continue;
        //     }
            
        //     // nums1[i] is even.
        //     // Subtract the odd number.
        //     // even - odd = odd
        //     if (i != oddIndex) {
        //         continue;
        //     }
        // }
        
        // return true;

// ======= my overall approach =======
     int n = nums1.size();
        vector<int> nums2;
        
        // Find an odd number
        int oddIndex = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 != 0) {
                oddIndex = i;
                break;
            }
        }
        
        // Case 1: All numbers are even
        if (oddIndex == -1) {
            for (int i = 0; i < n; i++) {
                nums2.push_back(nums1[i]);
            }
        }
        
        // Case 2: At least one odd number exists
        else {
            for (int i = 0; i < n; i++) {
                
                if (nums1[i] % 2 != 0) {
                    // Already odd
                    nums2.push_back(nums1[i]);
                }
                else {
                    // Even - odd = odd
                    nums2.push_back(nums1[i] - nums1[oddIndex]);
                }
            }
        }
        
        // Check whether all elements have the same parity
        bool allOdd = true;
        bool allEven = true;
        
        for (int i = 0; i < n; i++) {
            if (nums2[i] % 2 == 0)
                allOdd = false;
            else
                allEven = false;
        }
        
        return allOdd || allEven;

    }
};