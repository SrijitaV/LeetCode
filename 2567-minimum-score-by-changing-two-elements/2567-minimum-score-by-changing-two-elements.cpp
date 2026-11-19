class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        // given array ka size
        int n = nums.size();

        // sort kar lete hai kaam aega
        sort(nums.begin(), nums.end());

        // After sorting the array in ascending order,
        // we know that the maximum difference comes from
        // the smallest and largest elements.
        // Since we are allowed to change any two elements,
        // we need to eliminate the influence of these extreme values
        // to minimize the range.
        // There are only three possible ways to do this:
        // change the two smallest elements,
        // change the smallest and the largest elements, or
        // change the two largest elements.
        // These three cases cover all possibilities
        // because changing any two elements other than
        // these extreme combinations cannot produce a smaller range.
        // We calculate the remaining range for each case using the sorted
        // array.

        // Case 1: Change the two smallest elements
        // Remaining range = largest - third smallest
        int case1 = nums[n - 1] - nums[2];

        // Case 2: Change the smallest and largest elements
        // Remaining range = second largest - second smallest
        int case2 = nums[n - 2] - nums[1];

        // Case 3: Change the two largest elements
        // Remaining range = third largest - smallest
        int case3 = nums[n - 3] - nums[0];

        // For each case,
        // we calculate the difference between the largest and smallest elements
        // among the remaining unchanged elements.
        // We take the minimum of these three differences
        // because our objective is to minimize the maximum absolute difference.
        // Also, since we can change the two selected elements to the same
        // value, the minimum absolute difference (low score) can always be made
        // zero. Therefore, the overall score becomes just the minimum possible
        // range among the three cases. Hence, we return min({case1, case2,
        // case3}), which gives us the minimum achievable score.

        // Return the minimum possible score
        return min({case1, case2, case3});

        // Time: O(n logn)

        // Auxiliary space:
        //  Depends on the sorting implementation;
        //  typically O(log n) for std::sort.
    }
};