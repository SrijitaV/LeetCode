class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                }
            }
        }

        return result;

        // Time complexity: O(n^2)
        // Space complexity: O(n)
    }
};

/*
Step by Step Algorithm
Initialize Result List:

Create an empty list res to store the triplets whose sum is zero.
res = []
Sort the Input Array:

Sort the input array nums in non-decreasing order. Sorting the array helps in
avoiding duplicate triplets. nums.sort() Iterate Through the Array:

Iterate through each element in the sorted array nums.
for i in range(len(nums)):
Skip Duplicate Elements:

Check if the current element is a duplicate of the previous element and skip it
if it is. if i > 0 and nums[i] == nums[i-1]: continue Initialize Pointers:

Initialize two pointers j and k to point to the elements next to the current
element i and at the end of the array, respectively. j = i + 1 k = len(nums) - 1
Two-Pointer Approach:

Use a two-pointer approach with pointers j and k to find triplets whose sum
equals zero. while j < k: Calculate Total:

Calculate the total sum of the current triplet.
total = nums[i] + nums[j] + nums[k]
Adjust Pointers Based on Total:

If the total sum is greater than zero, decrement the k pointer to decrease the
total sum. if total > 0: k -= 1 If the total sum is less than zero, increment
the j pointer to increase the total sum. elif total < 0: j += 1 If the total sum
equals zero, add the triplet [nums[i], nums[j], nums[k]] to the result list res.
else:
    res.append([nums[i], nums[j], nums[k]])
Handle Duplicate Triplets:

Increment the j pointer to skip any duplicate elements.
j += 1
while nums[j] == nums[j-1] and j < k:
    j += 1
Return Result:

Return the list res containing all the unique triplets whose sum is zero.
return res
This algorithm efficiently finds all unique triplets in the given array nums
whose sum equals zero using a two-pointer approach. It avoids duplicate triplets
by skipping duplicate elements during traversal.
*/