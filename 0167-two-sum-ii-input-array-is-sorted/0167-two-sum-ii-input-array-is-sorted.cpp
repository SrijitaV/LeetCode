class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // appraoch - Since the array is sorted, if the sum is smaller than the
        // target, we move left++. If the sum is greater, we move right--.

        int left = 0, right = numbers.size() - 1;

        // Left aur right pointer array ke dono ends se start honge
        while (left < right) {
            int sum = numbers[left] + numbers[right];

            // Agar sum target ke equal hai, toh 1-based indices return kar do
            if (sum == target) {
                return {left + 1, right + 1};
            }

            // Agar sum target se chhota ya equal hai,
            // toh left pointer aage badhao taaki sum increase ho sake
            else if (sum <= target) {
                left++;
            }

            // Agar sum target se bada hai,
            // toh right pointer peeche lao taaki sum decrease ho sake
            else {
                right--;
            }
        }

        // Agar koi valid pair nahi mila, toh empty vector return hoga
        return {};

        // Time Complexity: O(n) ~ In the worst case, the left and right
        // pointers together traverse the array, and each pointer moves only
        // forward or backward.
        //  Space Complexity: O(1) ~ We use only a few integer variables (left,
        //  right, and sum). No extra data structure is used.
    }
};