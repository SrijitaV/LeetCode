class Solution {
public:
    int minMoves(vector<int>& nums) {

        // ------------------ most optimal solution -------------------

        // Intuition
        // Raising n-1 elements by 1 is the same, relative to the other element,
        // as lowering that single remaining element by 1. All that matters for
        // making everything equal is the differences between elements, and both
        // operations change those differences in exactly the same way. So the
        // problem becomes trivial: each move just lowers one element by 1, and
        // the cheapest target is the minimum value, since nothing needs to go
        // below it.

        // https://assets.leetcode.com/users/images/dd89fa30-efa9-4297-8d26-699d003a7111_1793504757.2122188.gif$0

        // Approach
        // 1. Reframe each move as "decrement one element by 1".
        // 2. Every element must be brought down to the minimum of the array.
        // 3. The number of moves for an element x is x - min.
        // 4. Total moves = sum(x_i - min) = sum - n * min.
        // 5. This is computed directly with one pass for the sum and one pass
        // for the minimum.

        return accumulate(nums.begin(), nums.end(), 0ll) -
               (nums.size() * ranges::min(nums));

        // Why 0ll instead of 0? ~ Because 0ll makes the accumulation happen
        // using long long, preventing integer overflow while calculating the
        // sum.

        // accumulate() calculates the sum of all array elements (0ll ensures
        // long long sum)

        // ranges::min(nums) finds the minimum element

        // nums.size() * min element = total value if every element were equal
        // to the minimum

        // ans = sum(nums) - (n * min(nums))

        // Time Complexity ~ O(n)
        // Space Complexity ~ O(1)

        // ------------------------------------------------------------------------

        // Answer = sum(nums) - (n * min(nums))

        // --------------- optimized brute force appraoch -----------------
        // int n = nums.size();
        // int sum = 0;
        // int min_nums = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     sum = sum + nums[i];
        //     min_nums = min(min_nums, nums[i]);
        // }
        // int ans = sum - (n * min_nums);
        // return ans;
        // Time Complexity ~ O(n)
        // Space Complexity ~ O(1)

        // ------------------ my brute force approach -----------------
        // int n = nums.size();
        // int sum = 0;
        // int min_nums = *min_element(nums.begin(), nums.end());
        // for (int i = 0; i < n; i++) {
        //     sum = sum + nums[i];
        // }
        // int ans;
        // ans = sum - (n * min_nums);
        // return ans;
        // Time Complexity ~ O(n)
        // Space Complexity ~ O(1)
    }
};

/*
Incrementing n-1 elements is equivalent to decrementing the remaining element,
when considering relative differences. The smallest element becomes our target
value. Every element must conceptually be reduced to the minimum. Moves required
for each element = nums[i] - min(nums). Sum all these differences.
*/

/*

Think about what happens when you increment n - 1 elements. Instead of
incrementing n - 1 elements, imagine doing the opposite: Decrement the remaining
one element by 1.

Why? Because incrementing all elements except one has the same effect on their
relative differences as decrementing the one excluded element.

So instead of making all elements equal by incrementing n-1 elements, we can
imagine: Decrementing the largest elements until all elements become equal to
the smallest element.

*/