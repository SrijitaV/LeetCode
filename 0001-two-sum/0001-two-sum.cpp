class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // --------------------- one pass hadh table (map) -------------------

        // It turns out we can do it in one-pass. While we are iterating and
        // inserting elements into the hash table, we also look back to check if
        // current element's complement already exists in the hash table. If it
        // exists, we have found a solution and return the indices immediately.

        // Stores number -> index
        unordered_map<int, int> hash; // Key: The number from the array, Value:
                                      // The index where that number appeared.

        for (int i = 0; i < nums.size(); i++) {

            // Number needed to reach target
            int need =
                target - nums[i]; // find what number you need to add to the
                                  // current number to get the target.

            // Check whether the required number was already seen
            //  hash.find(need) searches for the key need.
            //  hash.end() represents the position just past the last element,
            //  which is used to indicate that the key was not found when
            //  compared with the result of find().
            //  != hash.end() means the key was found.
            if (hash.find(need) != hash.end()) {
                return {hash[need], i}; // returns the two indices of the
                                        // numbers that add up to the target.
            }

            hash[nums[i]] = i; // If the required number was not found, we store
                               // the current number and its index in the map.
        }
        return {};

        // Time complexity: O(n) ~ We traverse the list containing n elements
        // only once. Each lookup in the table costs only O(1) time. Space
        // complexity: O(n) ~ The extra space required depends on the number of
        // items stored in the hash table, which stores at most n elements.

        // -------------- my brute force approach ----------------
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = (i + 1); j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};
        // Time Complexity - O(n^2)
        // Space Complexity - O(1)
    }
};