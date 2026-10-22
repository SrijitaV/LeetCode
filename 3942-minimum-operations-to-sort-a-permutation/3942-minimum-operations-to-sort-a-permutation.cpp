class Solution {
private:
    // ye function check karega ki given k se array ko
    // circularly traverse karne par elements sahi order mein hain ya nahi
    bool check(vector<int>& nums, int k) {

        // nums ka size
        int n = nums.size();

        // poora nums iterate krna
        for (int i = 0; i < n; i++) {

            // (k + i) % n se circular index milta hai
            // agar index n ke bahar jaata hai, toh wapas 0 se start hoga
            // humein check karna hai ki position i par value bhi i hi hai
            if (nums[(k + i) % n] != i) {

                // ek bhi mismatch mila toh array valid nahi hai
                return false;
            }
        }
        // saare elements sahi order mein mile hai
        return true;
    }

public:
    int minOperations(vector<int>& nums) {

        // nums ka size
        int n = nums.size();

        // array mein 0 kis index par hai, vo find kar re hai
        // k mein store hoga value 0 index ka
        int k = find(nums.begin(), nums.end(), 0) - nums.begin();

        // ans ko int max rakhna hai, initially
        // meaning koi valid solution ni mila hai
        int ans = INT_MAX;

        // case 1 - original array ko circularly check karna hai
        if (check(nums, k)) {

            // agar valid hai, toh doo possible operation counts mein se
            // jo minimum hai usko answer mein store kar lenge
            ans = min(k, n - k + 2);

            /*

            Calculate the minimum cost

            Suppose the index of 0 is k, and the array's circular order matches
            the sorted order.

            We can sort it in k left rotations. Alternatively, we can reverse,
            rotate left n-k times, and reverse again, costing n-k+2 operations.

            Therefore, the minimum cost for the original orientation is:

                min(k, n-k+2)

            For the reversed orientation, we need one reversal plus the
            rotations. We can achieve the required orientation using either k or
            n-k rotations, so its minimum cost is:

                min(k, n-k)+1

            These costs are only candidates. We must first verify that the
            corresponding circular order actually matches the sorted
            permutation.

            */
        }

        // case 2 : ab array ko reverse kar k check karenge
        reverse(nums.begin(), nums.end());

        // reverse hone ke baad 0 ka index change ho sakta hai,
        // isliye uska naya index j mein find kar rahe hain.
        int j = find(nums.begin(), nums.end(), 0) - nums.begin();

        // reversed array bhi valid circular order follow karta hai ya nahi?
        if (check(nums, j)) {
            // agar valid hai, toh is case ka minimum cost calculate karo.
            // min(j, n-j) mein dono directions ke counts compare honge.
            // +1 reverse operation ka extra cost represent karta hai.
            ans = min(ans, min(j, n - j) + 1);
        }

        // Agar dono cases mein se koi bhi valid nahi mila,
        // toh -1 return karenge. Otherwise minimum operations return karo.
        // return ans == INT_MAX ? -1 : ans;

        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};

// Time Complexity: O(n)
//-  find() takes O(n).
// - check() takes O(n).
// - reverse() takes O(n).
// - These operations run a constant number of times.
// Space Complexity: O(1)
// - Only a few integer variables are used.
// - No additional data structure is allocated.
// - reverse() modifies the array in place.