class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // Sorting + Hash Map

        // Initialize a hash map num_to_rank to store the mapping from each
        // number in arr to its corresponding rank
        map<int, int> num_to_rank;
        // The rank of an element is based on its position in a sorted array. To
        // determine the ranks, we first sort the array arr.

        // Create a copy of arr called sorted_arr
        vector<int> sorted_arr(arr);

        // Sort it so that sorted_arr is in ascending order.
        sort(sorted_arr.begin(), sorted_arr.end());

        // Initialize current rank to 1.
        int rank = 1;

        // Iterate through each element sorted_arr[i] in sorted_arr
        for (int i = 0; i < sorted_arr.size(); i++) {

            // If i > 0 and sorted_arr[i] > sorted_arr[i-1], then rank can be
            // incremented.
            if (i > 0 && sorted_arr[i] > sorted_arr[i - 1]) {
                rank++;
            }

            // Add the mapping (sortedArr[i], rank) to our num_to_rank
            num_to_rank[sorted_arr[i]] = rank;
        }

        // Iterate through each element arr[i] in input arr
        for (int i = 0; i < arr.size(); i++) {

            // Replace it with its rank: arr[i] = num_to_rank.get(arr[i])
            arr[i] = num_to_rank[arr[i]];
        }

        // Return arr
        return arr;
    }
};