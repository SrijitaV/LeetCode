class Solution {
public:
    vector<string> createGrid(int m, int n) {

        // The problem asks us to construct an m×n grid containing only the
        // characters . (free cell) and # (obstacle cell), such that there is
        // exactly one valid path from the top-left cell (0,0) to the
        // bottom-right cell (m−1,n−1).

        // Since each move along a path can only go right or down, we can
        // directly construct a valid solution by carving a single open
        // corridor: first move right along the first row from (0,0) to (0,n−1),
        // and then move down along the last column to (m−1,n−1).

        // Setting all cells along this corridor to . and all other cells to #
        // guarantees that exactly one valid path exists. From any cell in the
        // first row before the last column, moving down hits an obstacle,
        // forcing the path to continue moving right. Once the top-right corner
        // is reached, moving right is out of bounds, forcing the path down the
        // last column.

        vector<string> grid(m);

        // First row mein sabhi cells free rakhenge
        grid[0] = string(n, '.');

        // Baaki rows mein last column free rakhenge
        string row = string(n - 1, '#') + '.';

        // Har remaining row mein same pattern fill karenge
        for (int i = 1; i < m; i++) {
            grid[i] = row;
        }

        return grid;

        // Complexity Analysis
        // Let m and n be the number of rows and columns in the grid,
        // respectively.

        // Time complexity: O(mn).
        // Constructing each cell in the grid takes O(1) time, so the overall
        // time complexity is O(mn).

        // Space complexity: O(n).
        // A temporary string of length n is used to construct each row,
        // requiring O(n) auxiliary space (excluding the output grid).
    }
};