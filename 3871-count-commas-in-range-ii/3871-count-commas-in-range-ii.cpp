class Solution {
public:
// ========== Approach ==========  
    // The important observation is:
        // Numbers from 1 to 999 have 0 commas.
        // From 1,000 onward, every number has at least 1 comma.
        // From 1,000,000 onward, every number has at least 2 commas.
        // From 1,000,000,000 onward, every number has at least 3 commas.
        // Therefore, instead of checking every number individually, we count the contribution of each comma position.
    // For each p:
        // p = 1,000
        // All numbers from 1,000 to n contribute one comma.
    // Number of such numbers:
       // n - p + 1        
    // Then we move to the next comma position:
        // p = p × 1000
    // So p becomes:
        // 1,000
        // 1,000,000
        // 1,000,000,000
        // 1,000,000,000,000
        // ...
        // This is why we don't need a huge loop up to n.


// ========== Code ==========
    long long countCommas(long long n) {

        // p represents the number at which a new comma starts appearing.
        // First comma appears at 1,000.
        long long p = 1000;

        // Stores the total number of commas found.
        long long result = 0;

        // Continue as long as this comma position exists within n.
        while (p <= n)
        {
            // Numbers from p to n all have a comma at this position.
            // Number of integers from p to n:
                // n - p + 1
            // Add these commas to our total.
            result = result + (n - p + 1);

            // Move to the next comma position.
                // 1,000
                //      ↓ ×1000
                // 1,000,000
                //      ↓ ×1000
                // 1,000,000,000
                //      ↓ ×1000
                // ...
            p = p * 1000;
        }

        // Return the total number of commas.
        return result;
    }
};