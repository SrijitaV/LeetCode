class Solution {
public:
    int countPrimes(int n) {

        // We create an array of size n.
        // Every index represents a number, and initially we assume every number
        // is prime.
        vector<bool> prime(n, true);

        if (n <= 2) {
            return 0;
        }

        // 0 and 1 are not prime numbers.
        prime[0] = false;
        prime[1] = false;

        // We start from 2 and move forward.
        // If prime[i] is true, it means i is prime, so we eliminate its
        // multiples.
        for (int i = 2; i * i < n; i++) {

            if (prime[i]) {

                // Eliminate multiples
                // We keep adding i to j, marking every multiple as false.
                // j = i * i	Start eliminating from square of the prime
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int ans = 0;

        // Count all numbers that remain true.
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
            }
        }

        return ans;

    // Time Complexity : O(n log log n)
        // Space Complexity : O(n)
    }
};
