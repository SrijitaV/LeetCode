class Solution {
public:
    int reverseDegree(string s) {

        // ========= optimized code ===========
        int ans = 0;
        for (int i = 1; i <= s.size(); i++) {
            ans += (26 - (s[i - 1] - 'a')) * i;
        }
        return ans;

        // ===============================================================================================

        // ============ my code =============

        // map kar rahe hai character aur uski value ko

        // unordered_map<char, int> mp; // map with char as key, int as value

        // char ch = 'a'; // starting character
        // int n = 26;    // starting integer

        // loop 26 times for all letters a–z
        // for (int i = 0; i < 26; i++) {
        //     mp[ch] = n; // insert key-value pair
        //     ch++;       // move to next character
        //     n--;        // decrement integer
        // }

        // given string se result generate kar re hai

        // int result = 0;

        // for (int i = 0; i < s.length(); i++) {
            // s[i] → current character in the string
            // mp[s[i]] → value mapped to that character (like a=26, b=25, etc.)
            // (i + 1) → 1-indexed position of the character in the string
            // multiply and add to result
        //     result = result + (mp[s[i]] * (i + 1));
        // }

        // return result;

        //     ⏱ Time Complexity
        // Map creation loop: Runs 26 times → 𝑂(26) = 𝑂(1) (constant time)
        // Result calculation loop: Runs for each character in the string →
        // 𝑂(𝑛), where 𝑛 = 𝑠.𝑙en Total: 𝑂(𝑛)
        //     💾 Space Complexit
        // Unordered map: Stores 26 key-value pairs → 𝑂(26) = 𝑂(1
        // Other variables: Constant space.
        // Total: 𝑂(1)
        }
    };