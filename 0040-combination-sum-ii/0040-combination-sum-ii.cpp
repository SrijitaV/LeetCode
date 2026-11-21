class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans = {{}};
        vector<int> sums = {0};

        int prevSize = 0;

        for (int i = 0; i < candidates.size(); i++) {

            int currSize = ans.size();
            int start = 0;

            // Handle duplicate values
            if (i > 0 && candidates[i] == candidates[i - 1]) {
                start = prevSize;
            }

            for (int j = start; j < currSize; j++) {

                int newSum = sums[j] + candidates[i];

                if (newSum > target)
                    continue;

                vector<int> temp = ans[j];
                temp.push_back(candidates[i]);

                ans.push_back(temp);
                sums.push_back(newSum);
            }

            prevSize = currSize;
        }

        vector<vector<int>> result;

        for (int i = 0; i < ans.size(); i++) {
            if (sums[i] == target) {
                result.push_back(ans[i]);
            }
        }

        return result;

        // sort(candidates.begin(), candidates.end());

        // vector<vector<int>> ans;

        // for (int i = 0; i < candidates.size(); i++) {

        //     int temp_sum = 0;

        //     temp_sum = temp_sum + candidates[i];

        //     vector<int> temp_pair;

        //     temp_pair.push_back(candidates[i]);

        //     for (int j = i + 1; j < candidates.size(); j++) {

        //         temp_sum = temp_sum + candidates[j];

        //         if (temp_sum <= target) {
        //             temp_pair.push_back(candidates[j]);
        //         } else {
        //             break;
        //         }
        //     }

        //     ans.push_back(temp_pair);
        // }

        // return ans;
    }
};