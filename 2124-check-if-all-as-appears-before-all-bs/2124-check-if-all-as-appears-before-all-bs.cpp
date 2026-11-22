class Solution {
public:
    bool checkString(string s) {

        // intution :
        // instead of checking whether all as occur before all bs directly, 
        // we only need to check whether an invalid adjacent pair ba exists.

        // Checking every adjacent pair of characters
        for (int i = 0; i < s.length() - 1; i++) {

            // If 'b' comes before 'a', condition is violated
            if (s[i] > s[i + 1]) {
                return false;
            }
        }

        // No invalid pair found, so all 'a's appear before 'b's
        return true;

        // Time Complexity: O(n)
        // We traverse the string once and compare adjacent characters.

        // Space Complexity: O(1)
        // No extra space is used.
    }
};