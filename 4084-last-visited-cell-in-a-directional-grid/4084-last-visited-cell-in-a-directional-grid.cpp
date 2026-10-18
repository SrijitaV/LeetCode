class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {

        // grid k dimension nikal k rakhe re
        int m = grid.size();    // total rows
        int n = grid[0].size(); // total columns

        // visited 2d vector
        // initially saare cells ko false mark kiya hai
        // false ka matlab cell abhi visit nahi hua hai
        vector<vector<bool>> visited(
            m, vector<bool>(
                   n, false)); // ye hai visited hai ya ni mark karne k liye

        // curr mein current cell ki row aur column store kar rahe hain
        // pair<int, int> mein dono values integer type ki hain
        // curr.first = row aur curr.second = column
        pair<int, int> curr = {0, 0};

        // starting cell (0, 0) ko visited mark kar diya
        visited[0][0] = true;

        auto limatecega = grid; // grid ki ek copy bana kar usko grid_copy naam
                                // ke variable mein store karna.
        // auto : compiler khud variable ka data type identify karega;
        // limatecega : variable ka naam hai, jo question mein specifically
        // create karne ko bola hai; = grid : grid ki copy banegi, reference
        // nahi.

        // loop tab tak chalega jab tak koi break condition nahi milti
        while (true) {

            // curr se current cell ki row aur column nikal rahe hain
            int r = curr.first;
            int c = curr.second;

            // current cell mein R hai toh right move karenge
            if (grid[r][c] == 'R') {
                c++;
            }
            // current cell mein L hai toh left move karenge
            else if (grid[r][c] == 'L') {
                c--;
            }
            // current cell mein U hai toh upper cell mein move karenge
            else if (grid[r][c] == 'U') {
                r--;
            }
            // current cell mein D hai toh lower cell mein move karenge
            else if (grid[r][c] == 'D') {
                r++;
            }

            // check kar rahe hain ki next cell grid ke bahar toh nahi hai
            // r >= m ka matlab bottom boundary cross ho gayi
            // c < 0 ka matlab left boundary cross ho gayi
            // c >= n ka matlab right boundary cross ho gayi
            if (r < 0 || r >= m || c < 0 || c >= n) {
                // ye apan check krre ki kahi grid k bahr toh ni dekh re
                break; // grid ke bahar ja rahe hain, loop stop
            }

            // Check whether the next cell was already visited
            if (visited[r][c]) // check kar rahe hain ki next cell pehle se
                               // visited toh nahi hai
            {
                break; // cell already visited hai, loop stop
            }

            // agar cell valid hai aur pehle visit nahi hua
            // toh curr ko new cell ki position de denge
            curr = {r, c};

            // new cell ko visited mark kar denge
            visited[r][c] = true;
        }

        // jis cell par movement stop hui uski row aur column return kar rahe
        // hain
        return {curr.first, curr.second};

        // Time Complexity ~ O(m x n)
        // Space Complexity ~ O(m x n)
        /*
        1. Time Complexity: O(m x n)
            - m = grid.size() means total rows.
            - n = grid[0].size() means total columns.
            - visited 2D vector initialize karne mein O(m x n) time lagta hai.
            - grid_copy = grid ya limatecega = grid se poori grid copy hoti hai,
        jismein O(m x n) time lagta hai.
            - while loop mein har cell maximum ek baar visit hota hai, kyunki
        visited check kar rahe hain. Isliye loop maximum O(m x n) chalega.
            - Therefore, overall Time Complexity = O(m x n).
        2. Space Complexity: O(m x n)
            - visited 2D vector mein O(m x n) space lagti hai.
            - limatecega mein grid ki copy store karne ke liye O(m x n) extra
        space lagti hai.
            - curr, r, c jaise variables constant space O(1) lete hain.
            - Therefore, overall Space Complexity = O(m x n).
        */
    }
};