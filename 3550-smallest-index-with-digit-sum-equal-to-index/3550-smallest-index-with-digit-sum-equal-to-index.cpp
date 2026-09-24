class Solution {
private:
    // Function to find the sum of digits of a number
    int fSum(int n) {
        int ans = 0;

        // Convert number into string
        string s = to_string(n);

        // Traverse through each digit
        for (int i = 0; i < s.length(); i++) {
            // Convert character digit into integer and add
            ans = ans + (s[i] - '0');
        }

        return ans;
    }

public:
    int smallestIndex(vector<int>& nums) {

        // Traverse through all elements of the array
        for (int i = 0; i < nums.size(); i++) {
            // Find sum of digits of current element
            int sum = fSum(nums[i]);

            // If digit sum is equal to index, return index
            if (sum == i) {
                return i;
            }
        }

        // If no such index is found
        return -1;
    }
};

// Complexity

// Let n = nums.size() and d = number of digits in a number.

// Time Complexity: O(n × d)
// We traverse all n elements.
// For each element, fSum() takes O(d) to calculate the digit sum.
// So overall: O(n × d)
// Space Complexity: O(d)
// to_string(n) creates a string containing the digits.
// So the extra space is O(d).