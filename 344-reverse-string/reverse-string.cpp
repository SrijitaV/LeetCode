class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(); 
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int temp; 
            temp = s[right]; 
            s[right] = s[left];
            s[left] = temp; 

            right--;
            left++;
        }
    }
};