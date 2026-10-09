class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        // --------- optimal solution ----------

        vector<int> result;
        int i = num.size() - 1;

        while (i >= 0 || k > 0) {

            if (i >= 0) {
                k = k + num[i];
                i--;
            }

            result.push_back(k % 10);
            k = k / 10;
        }

        reverse(result.begin(), result.end());
        return result;

        // Time complexity: O(n + logK)
        // Space complexity: O(n + logK)

        // -------------- my brute force approach --------------
        // int given_num = 0;
        // for (int i = 0; i < num.size(); i++)
        // {
        //     given_num = given_num * 10 + num[i];
        // }

        // int ans;
        // ans = given_num + k;

        // vector<int> result;
        // while(ans > 0)
        // {
        //     result.push_back(ans % 10);
        //     ans /= 10;
        // }

        // reverse(result.begin(), result.end());
        // return result;

        // code fat gaya - poora submit ni hua
    }
};