class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};             // frequency of each letter in magazine
        for (int i = 0; i < magazine.size(); i++)             // character count in magazine 
            count[magazine[i] - 'a']++;              // ch - 'a' converts letters into indexes
        for( int i = 0; i < ransomNote.size(); i++)
        {
            char ch = ransomNote[i];
            if (count[ch - 'a'] == 0)                // if this character is not available
                return false; 
            count[ch - 'a']--;            // consuming one occurrence of this character
        }
        return true;
    }
};