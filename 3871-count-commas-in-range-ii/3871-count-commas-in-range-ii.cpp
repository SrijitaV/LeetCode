class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000, result = 0; 
        while (p <= n)
        {
            result = result + (n - p + 1);
            p = p * 1000;
        }
        return result;
    }
};