class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; 
        int n = matrix.size();          // rows
        int m = matrix[0].size();       // cols
        int total_elements = (m * n); 
        
        int startingrow = 0; 
        int endingrow = n - 1;
        int endingcol = m - 1;
        int startingcol = 0;

        int count = 0; 
        while (count < total_elements)
        {
            // printing starting row
            for (int i = startingcol; ((i <= endingcol) && (count < total_elements)); i++)
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;

            // printing ending col
            for (int i = startingrow; ((i <= endingrow) && (count < total_elements)); i++)
            {
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--; 

            // printing ending row
            for(int i = endingcol;((i >= startingcol) && (count < total_elements)); i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;

            // printing starting col
            for (int i = endingrow; ((i >= startingrow) && (count < total_elements)); i--)
            {
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans;
    }
};