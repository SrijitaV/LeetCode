class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // count how many times each number appears - tracking frequency 
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end()); 
        vector<int> count(maxi - mini + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            count[nums[i] - mini]++;

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

        return nums;
    }
};