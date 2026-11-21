class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        // Sort the array so that duplicate elements are adjacent.
        // This also helps us avoid generating duplicate combinations.

        vector<vector<int>> ans = {{}};
        // Stores all combinations generated so far.
        // Initially, we have one combination: an empty vector.

        vector<int> sums = {0};
        // Stores the sum of each corresponding combination in ans.
        // Initially, the sum of the empty combination is 0.

        int prevSize = 0;
        // Stores the size of ans before processing the previous element.
        // Used to handle duplicate candidates.

        for (int i = 0; i < candidates.size(); i++) {

            int currSize = ans.size();
            // Stores the current number of combinations.
            // We only extend combinations that existed before this iteration.

            int start = 0;
            // Determines the starting index from which we extend combinations.

            // Handle duplicate elements
            if (i > 0 && candidates[i] == candidates[i - 1]) {
                start = prevSize;
                // If the current element is a duplicate of the previous one,
                // extend only combinations generated in the previous iteration.
                // This allows using duplicate values without creating duplicate
                // combinations.
            }

            for (int j = start; j < currSize; j++) {

                int newSum = sums[j] + candidates[i];
                // Calculate the new sum by adding the current candidate
                // to an already existing combination.

                if (newSum > target)
                    continue;
                // Skip this combination if its sum exceeds the target.

                vector<int> temp = ans[j];
                // Copy the existing combination into a temporary vector.

                temp.push_back(candidates[i]);
                // Include the current candidate in the combination.

                ans.push_back(temp);
                // Store the newly generated combination.

                sums.push_back(newSum);
                // Store its corresponding sum at the same index in sums.
            }

            prevSize = currSize;
            // Update the previous size for duplicate handling
            // in the next iteration.
        }

        vector<vector<int>> result;
        // Stores only those combinations whose sum equals the target.

        for (int i = 0; i < ans.size(); i++) {

            if (sums[i] == target) {
                result.push_back(ans[i]);
                // Add the combination to the final result
                // if its sum is exactly equal to the target.
            }
        }

        return result;
        // Return all unique combinations whose sum equals the target.

        // Time Complexity: O(N * 2^N)
        // Sorting takes O(N log N).
        // Generating combinations takes O(N * 2^N) in the worst case,
        // because there can be up to 2^N subsets and copying a combination
        // can take O(N) time.

        // Space Complexity: O(N * 2^N)
        // The ans vector stores up to 2^N combinations,
        // each containing at most N elements.
        // The sums vector requires O(2^N) additional space.
        // The result vector can also store up to O(N * 2^N) elements.
    }
};