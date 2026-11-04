class Solution {
public:
    int addDigits(int num) {

        // jab tak number single digit nahi ban jata
        while (num >= 10) {
            int n = 0;
            int sum = 0;

            // ye number ke individual digits extract karega
            while (num >= 1) {
                n = num % 10;   // last digit nikalo
                sum = sum + n;  // digit ko sum mein add karo
                num = num / 10; // last digit remove karo
            }

            // ab sum ko new number bana denge
            // aur dobara digits ka sum calculate hoga
            num = sum;
        }

        // jab single digit bach jayega toh return kar denge
        return num;

        // Time Complexity: O(log n)
        // - Extracting all digits of a number takes O(log n) time.
        // - We repeat the digit-summing process until a single digit remains.
        // - The number of digits decreases after every summation.
        // More precisely, the total work is O(log n), where n is the original
        // input number.

        // Space Complexity: O(1)
        // - We use only two extra variables: n and sum.
        // - No extra array or data structure is used.
    }
};