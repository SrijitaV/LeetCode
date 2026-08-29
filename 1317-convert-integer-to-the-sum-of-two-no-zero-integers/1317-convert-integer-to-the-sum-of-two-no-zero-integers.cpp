class Solution {
private:
    bool zero(int n) {
        string s = to_string(n);
        if (s.find('0') != string::npos) {
            return false;
        } // mil gaya
        else {
            return true;
        } // ni mila
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        int low = 0, high = n;
        while (low <= high) {
            if ((zero(low)) && (zero(high))) {
                return {low, high};
                // if ((low + high) == n) 
            }
            low++;
            high--;
        }
        return {};
    }
};