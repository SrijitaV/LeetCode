class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        // Step 1: Precompute column maxima
        vector<int> colMax(n, INT_MIN);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        // Step 2: Fill answer matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    ans[i][j] = colMax[j];
                } else {
                    ans[i][j] = matrix[i][j];
                }
            }
        }

        return ans;
    }
};