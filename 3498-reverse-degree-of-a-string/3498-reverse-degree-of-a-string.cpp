class Solution {
public:
    int reverseDegree(string s) {

        // map kar rahe hai character aur uski value ko

        unordered_map<char, int> mp; // map with char as key, int as value

        char ch = 'a'; // starting character
        int n = 26;    // starting integer

        // loop 26 times for all letters a–z
        for (int i = 0; i < 26; i++) {
            mp[ch] = n; // insert key-value pair
            ch++;       // move to next character
            n--;        // decrement integer
        }

        // given string se result generate kar re hai

        int result = 0; 

        for (int i = 0; i < s.length(); i++) {
            result = result + (mp[s[i]] * (i + 1)); 
        }

        return result; 
    }
};