class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {

        // ye initially answer ko {-1, -1} rakhega agar koi valid pair nahi mila
        vector<int> ans = {-1, -1};

        // ye abhi tak mile maximum product ko store karega
        int product = 0;

        // ye check karega ki abhi tak koi valid pair mila hai ya nahi
        bool found = false;

        // ye loop last index se start hoke 0 tak jayega
        for (int i = nums.size() - 1; i >= 0; i--) {

            // ye har index ko i ke saath pair banake check karega
            for (int j = 0; j < nums.size(); j++) {

                // check karenge ki dono elements ka sum target ke equal hai
                // nums[i] > nums[j] se given condition satisfy hogi
                // i != j ensure karega ki dono indices distinct hon
                if (((nums[i] + nums[j]) == target) &&
                    ((nums[i] > nums[j]) && i != j)) {

                    // ye current valid pair ka product calculate karega
                    int pro = nums[i] * nums[j];

                    // agar pehla valid pair mila hai ya current product
                    // ab tak ke maximum product se bada hai
                    if (!found || pro > product) {

                        // maximum product update karenge
                        product = pro;

                        // answer mein current pair ke indices store karenge
                        ans = {i, j};

                        // ab valid pair mil chuka hai
                        found = true;
                    }
                }
            }
        }

        // maximum product wala valid pair return karenge
        // agar koi valid pair nahi mila toh {-1, -1} return hoga
        return ans;

        // Time Complexity: O(n^2)
        // - Outer loop runs n times.
        // - Inner loop also runs n times.
        // - So total iterations = n \times n.



        // Space Complexity: O(1)
        // - We use only a fixed number of extra variables.
        // - The answer vector has a fixed size of 2.
    }
};