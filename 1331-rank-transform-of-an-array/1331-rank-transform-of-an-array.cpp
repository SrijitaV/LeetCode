class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Sorting + Hash Map

        // Initialize a hash map num_to_rank to store the mapping from each
        // number in arr to its corresponding rank
        map<int, int> num_to_rank;
        // We can store the ranks in a hash map, where each key is a number from
        // arr and each value is its rank.

        // Create a copy of arr called sorted_arr
        vector<int> sorted_arr(arr);
        // In the sorted array, the first element gets rank 1 because it is the
        // smallest.
        // The second element gets rank 2 if it is larger than the first.
        // If it is equal to the first element, it also gets rank 1.
        // In general, if an element's value is different from the previous
        // element's value, its rank is one more than the previous element's
        // rank.
        // If the values are the same, they share the same rank.

        // Sort it so that sorted_arr is in ascending order.
        sort(sorted_arr.begin(), sorted_arr.end());
        // The rank of an element is based on its position in a sorted array.
        // To determine the ranks, we first sort the array arr.

        // Initialize current rank to 1.
        int rank = 1;
        // We will use a variable rank, starting at 1,
        // to track the rank as we go through the sorted array.

        // Iterate through each element sorted_arr[i] in sorted_arr
        for (int i = 0; i < sorted_arr.size(); i++) {

            // If i > 0 and sorted_arr[i] > sorted_arr[i-1], then rank can be
            // incremented.
            if (i > 0 && sorted_arr[i] > sorted_arr[i - 1]) {
                rank++;
            }
            // For each element, we check if its value is greater than the
            // previous element's value. If it is, we increment rank and store
            // the new rank in the map. If it isn't, we store the same rank as
            // the previous element.

            // Add the mapping (sortedArr[i], rank) to our num_to_rank
            num_to_rank[sorted_arr[i]] = rank;
        }

        // Iterate through each element arr[i] in input arr
        for (int i = 0; i < arr.size(); i++) {

            // Replace it with its rank: arr[i] = num_to_rank.get(arr[i])
            arr[i] = num_to_rank[arr[i]];
        }
        // After calculating the ranks for all elements, we can replace each
        // element in the original array arr with its rank by looking it up in
        // the hash map.

        // Return arr
        return arr;

        // Complexity Analysis
        // Let N be the size of arr.

        // Time Complexity: O(N x logN)
        // Sorting sorted_arr takes O(N x logN) time.
        // Iterating through arr and sorted_arr and inserting/looking up the
        // rank for each number in our hash map takes in total O(N x logN) time.
        // Thus, the total time complexity is O(N x logN)

        // Space complexity: O(N + S)
        // Creating a copy of arr to be sorted will take O(N) time.
        // The space taken by the sorting algorithm (S) depends on the language
        // of implementation.
    }
};