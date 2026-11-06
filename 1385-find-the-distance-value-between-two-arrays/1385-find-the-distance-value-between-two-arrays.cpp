class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        // -------------------- brinary search approach --------------------

        // If arr2 is sorted, the elements in arr2 closest to x are:
        // 1. The smallest element greater than or equal to x
        // (found via binary search).
        // 2. The largest element strictly less than x
        // (the element immediately preceding the binary search result).

        // If neither of these two closest elements falls within distance d of
        // x, then no element in arr2 can fall within distance d. Therefore, we
        // can sort arr2 and use binary search to locate these two candidates
        // for each element in arr1. If both candidates satisfy the condition,
        // we increment the answer by 1.

        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int i = 0; i < arr1.size(); i++) {
            unsigned p =
                lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            bool ok = true;
            if (p < arr2.size()) {
                ok = ok & (arr2[p] - arr1[i] > d);
            }
            if (p - 1 >= 0 && p - 1 <= arr2.size()) {
                ok = ok & (arr1[i] - arr2[p - 1] > d);
            }

            ans = ans + ok;
        }

        return ans;

        // -----------------------------------------------------------------
        // ---------------------- brute foce appraoch ----------------------

        // Intuition
        // - We can directly simulate the process described in the problem:
        // for each element x in arr1,
        // check whether ∣x−y∣>d holds for every element y in arr2.
        // - If this condition holds for all elements in arr2,
        // increment the answer by 1.

        // int ans = 0;
        // for (int i = 0; i < arr1.size(); i++) {
        //     bool ok = true;

        //     for (int j = 0; j < arr2.size(); j++) {
        //         ok = ok & (abs(arr1[i] - arr2[j]) > d);
        //     }

        //     ans = ans + ok;
        // }

        // return ans;

        // Complexity Analysis
        //         Let n and m be the numbers of elements in arr1 and arr2,
        //         respectively.

        // Time complexity: O(n×m).
        // - We iterate through each of the n elements in arr1, and for each
        // element, compare it against all m elements in arr2.
        // - Each difference calculation and comparison takes O(1) time,
        // yielding an overall time complexity of O(n×m).

        // Space complexity: O(1).
        // - Only a few variables are used to maintain the counts and iteration
        // states, so the space complexity is O(1).
    }
};