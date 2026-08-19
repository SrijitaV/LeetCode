class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; 
        // for first and second level 
        result.push_back({1}); 
        if (numRows >= 2)
            result.push_back({1, 1});       
        // for third to last 
        for (int i = 2; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);         // result[i][1] = 1; result[i][i] = 1;   ~ row full of 1 
            for (int j = 1; j < i; j++)
            {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(row);
        }
        return result;    
    }
};