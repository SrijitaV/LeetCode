class Solution {
public:
    int minMergedInteger(vector<int>& nums) {

        // Stores the total number of elements in the array.
        int n = nums.size();
        // given array ka size

        // Stores the minimum merged integer found so far.
        int result = INT_MAX;
        // ye minimum merged number store karega

        for (int i = 0; i < n - 1; i += 2) {

            // i +=2 : question specifically asks you
            // to merge elements in non-overlapping pairs:
            // nums[0] with nums[1], nums[2] with nums[3], nums[4] with nums[5]
            // Skips to the next pair after processing the current pair.

            // Converts the first integer of the pair into a string.
            string first = to_string(nums[i]);
            // ye first number ke digits ko string mein convert karega

            // Converts the second integer of the pair into a string.
            string second = to_string(nums[i + 1]);
            // ye second number ke digits ko string mein convert karega

            // Concatenates both strings to form the merged number.
            string number = first + second;
            // ye dono strings ko concatenate karega
            // first ke digits pehle aur second ke digits baad mein aayenge

            // Converts the merged string back into an integer.
            int ans = stoi(number);
            // ye concatenated string ko integer mein convert karega

            // Updates the minimum value by comparing the current
            // merged number with the previous minimum.
            result = min(result, ans);
            // ye ab tak ke minimum merged number ko update karega
        }

        // Returns the smallest merged integer among all pairs.
        return result;
        // ye sabhi merged numbers mein se minimum return karega

        // iterating given arrya once
        // TC: O(n)
        // The loop runs from i = 0 to n - 1, incrementing i by 2.
        // Therefore, it iterates approximately n/2 times.
        // In every iteration, we perform string conversion (to_string),
        // concatenation and integer conversion (stoi). Since nums[i] <= 1000,
        // the number of digits is bounded, so these operations take constant
        // time, O(1).
        // Therefore, overall TC = O(n/2) = O(n).

        // since the temporary strings have bounded length due to the
        // constraints.
        // SC: O(1)
        // We are using only a few extra variables: first, second,
        // number, ans and result.
        // The temporary strings have a maximum bounded length because each
        // number is at most 1000. We are not using any extra array, vector or
        // data structure that grows with input size.
        // Therefore, SC = O(1)}.
    }
};