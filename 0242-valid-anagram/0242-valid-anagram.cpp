class Solution {
public:
    bool isAnagram(string s, string t) {
        // basic sorting the strings and then comparing approach 
        // if (s.size() != t.size())
        //     return false;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == t[i])
        //         continue;
        //     else
        //         return false;
        // }
        // return true;

        // make frequency table for one increase then decrease and then check for zero
        int freq[256] = {0};
        for (int i = 0; i < s.size(); i++)
            freq[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            freq[t[i]]--; 
        for (int i = 0; i < 256; i++)
        {
            if (freq[i] != 0)
                return false; 
        }      
        return true; 
    }
};