class Solution {
public:
    int minMoves(vector<int>& nums) {

        // Answer = sum(nums) - (n * min(nums))

        // --------------- optimized brute force appraoch -----------------
        int n = nums.size();
        int sum = 0;
        int min_nums = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            min_nums = min(min_nums, nums[i]);
        }
        int ans = sum - (n * min_nums);
        return ans;
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