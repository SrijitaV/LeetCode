class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());
        unordered_map<int, int> rank;
        for (int i = 0; i < sorted.size(); i++)       // sorted array ko uski score k hisaab se rank de re hai 
        {
            rank[sorted[i]] = i + 1;        // jo score sorted[i] mein hai uski rank i+1 kardo
        }
        vector<string> ans(sorted.size());
        for (int i = 0; i < sorted.size(); i++)
        {
            int r = rank[score[i]];
            if (r == 1)
                ans[i] = "Gold Medal";
            else if (r == 2)
                ans[i] = "Silver Medal";
            else if (r == 3)
                ans[i] = "Bronze Medal";
            else
                ans[i] = to_string(r);
        }
        return ans;
    }
};