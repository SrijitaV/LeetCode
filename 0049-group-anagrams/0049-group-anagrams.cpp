class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ~~~~~~~~~~~ METHOD 1 ~~~~~~~~~~~~
        // idea :
        // identify anagram w.r.t each string - then group division
        // using map - key for sorted string (grouping with the help of the
        // map), value for given string eat (str) -> sort : act (s) so, string :
        // art and corresponding vector eat

        map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        int i = 0;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
            i++;
        }

        return ans;

        // ~~~~~~~~~~~ METHOD 2 ~~~~~~~~~~~~
        // sort in
    }
};