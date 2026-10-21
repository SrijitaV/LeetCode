class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // ------------------ two pointer approach ------------------
        int a1 = m - 1, a2 = n - 1, k = m + n - 1;

        while (a2 >= 0) { // jab tak nums2 ke elements khatam nahi hote
            if (a1 >= 0 && nums1[a1] > nums2[a2]) {
                // agar nums1 ka element bada hai
                // bade element ko last position pe daal do
                nums1[k] = nums1[a1];
                a1--; // nums1 ke pointer ko peeche karo
            } else {
                // warna nums2 ka element last position pe daal do
                nums1[k] = nums2[a2];
                a2--; // nums2 ke pointer ko peeche karo
            }
            k--; // next position pe jaane ke liye
        }
        // Time Complexity (TC): O(m+n)
        // Space Complexity (SC): O(1)

        // ---------------------------------------------------------------------

        // ------------------ my brute force appraoch ------------------
        // int j = 0;
        // for (int i = m; i < (m + n); i++) {
        //     nums1[i] = nums2[j];
        //     j++;
        // }
        // sort(nums1.begin(), nums1.end());
        // return;

        // Time Complexity: O((m+n) log(m+n))
        // 1. Copy nums2 into nums1: O(n)
        // 2. Sort nums1: O((m+n) log(m+n)), since its size is m+n.
        // Therefore, the overall TC is : O(n+(m+n) log(m+n))
        // Simplified : O((m+n) log(m+n))

        // Space Complexity: O(log(m+n)) auxiliary space
        // 1. The copying operation uses O(1) extra space.
        // 2. std::sort() typically uses O(log(m+n)) auxiliary stack space with
        // introsort. Therefore : O(log(m+n))
    }
};