class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") {
            return true;
        }
        // iterate karenge s given string par, two pointer k sath mein
        int left = 0, right = s.length() - 1;
        while (left < right) {
            // other than letter kuch bhi hua toh ignore kar denge jaise -
            // comma,space, collon, etc fir sabse pehle tolower kar denge agar
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};