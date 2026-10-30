class Solution {
public:
    int subtractProductAndSum(int n) {

        int product = 1; // ye sabhi digits ka product store karega

        int sum = 0; // ye sabhi digits ka sum store karega

        while (n > 0) {

            int digit = n % 10; // ye last digit nikalega

            product *= digit; // ye product me digit multiply karega

            sum += digit; // ye sum me digit add karega

            n /= 10; // ye last digit ko remove karega
        }

        return product - sum; // ye product or sum ka difference return karega

        // Time Complexity: O(log₁₀ n)
        // - The while loop runs once for each digit of n.
        // - An integer n has approximately log₁₀(n) digits.

        // Space Complexity: O(1)
        // - Only a fixed number of variables (product, sum, digit) are used.
        // - No extra data structure is required.
    }
};