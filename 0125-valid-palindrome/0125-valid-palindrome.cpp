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
                // dono characters ko lowercase mein convert karke compare
                // karenge taaki 'A' aur 'a' ko same consider karein
                if (tolower(s[left]) != tolower(s[right])) {
                    return false; // agar match nahi hua toh palindrome nahi hai
                }
                // agar dono characters match ho gaye toh pointers ko aage badha
                // denge left right ki taraf aur right left ki taraf move karega
                left++;
                right--;
            }
        }

        return true; // agar saare characters match ho gaye toh string palindrome hai

        // Time Complexity : O(n)
        // Space Complexity : O(1)
    }
};