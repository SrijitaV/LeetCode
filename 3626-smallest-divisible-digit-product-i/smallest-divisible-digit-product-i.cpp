class Solution {
private: 
    int productofN (int n)
    {
        int ans = 1; 
        for (int i = 0; n > 0; i++)
        {
            int digit = n % 10; 
            ans = digit * ans; 
            n = n / 10; 
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        int temp = n; 
        while(true)
        {
            int ans = productofN(temp);
            if ((ans % t) == 0)
                return temp;    
            temp++;
        }
        return 0;
    }
};