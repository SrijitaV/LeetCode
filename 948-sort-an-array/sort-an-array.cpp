class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // counting sort 

        // max and min element 
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end()); 
                    // TC = O(n) + O(n) = O(n)
        vector<int> count(maxi - mini + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            count[nums[i] - mini]++;
                   // Time = O(k), Space = O(k)    here k is the range of values 

        // putting elemts into original array in sorted order 
        int ptr = 0; 
        for (int i = 0; i < count.size(); i++)
        {
            while (count[i] > 0)
            {
                nums[ptr] = i + mini;
                ptr++;
                count[i]--;
            }
        }
                   //  Time = O(n), Space = O(1)

        return nums;
    }
};