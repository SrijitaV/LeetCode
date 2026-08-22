class Solution {
public:
    bool checkDivisibility(int n) {
        int c = n; // original value
        int sum = 0, product = 1;
        while (n > 0) {
            int x = n % 10;
            sum = sum + x;
            product = product * x;
            n = n / 10;
        }
        return ((c % (sum + product)) == 0);
        // n is divisible by the sum of digit sum AND digit product.
    }
};