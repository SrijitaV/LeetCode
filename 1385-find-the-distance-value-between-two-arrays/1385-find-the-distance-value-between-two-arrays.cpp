class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        // -----------------------------------------------------------------
        // ---------------------- brute foce appraoch ----------------------

        // Intuition
        // - We can directly simulate the process described in the problem:
        // for each element x in arr1,
        // check whether ∣x−y∣>d holds for every element y in arr2.
        // - If this condition holds for all elements in arr2,
        // increment the answer by 1.

        int ans = 0;
        for (int i = 0; i < arr1.size(); i++) {
            bool ok = true;

            for (int j = 0; j < arr2.size(); j++) {
                ok = ok & (abs(arr1[i] - arr2[j]) > d);
            }

            ans = ans + ok;
        }

        return ans;

// Complexity Analysis
//         Let n and m be the numbers of elements in arr1 and arr2, respectively.

// Time complexity: O(n×m).
// - We iterate through each of the n elements in arr1, and for each element, 
// compare it against all m elements in arr2. 
// - Each difference calculation and comparison takes O(1) time, 
// yielding an overall time complexity of O(n×m).

// Space complexity: O(1).
// - Only a few variables are used to maintain the counts and iteration states, 
// so the space complexity is O(1).
    }
};