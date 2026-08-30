class Solution {
public:
    long long power(long long x, long long y) {

        long long result = 1;
        long long MOD = 1000000007;

        while (y > 0) {

            if (y % 2 == 1) {
                result = (result * x) % MOD;
            }

            x = (x * x) % MOD;
            y = y / 2;
        }

        return result;
    }

    int sumDecoded(vector<long long>& nums) {

        long long ans = 0;
        long long MOD = 1000000007;

        for (int i = 0; i < nums.size(); i++) {

            // 1. Get width
            int width = nums[i] % 10;

            // 2. Get d
            long long d = nums[i] / 10;

            // 3. Convert d to string
            string s = to_string(d);

            // 4. Get x
            string xs = s.substr(0, width);
            long long x = stoll(xs);

            // 5. Get y
            string ys = s.substr(width);
            long long y = stoll(ys);

            // 6. Calculate x^y % MOD
            long long decode = power(x, y);

            // 7. Add to answer
            ans = (ans + decode) % MOD;
        }

        return ans;
    }
};