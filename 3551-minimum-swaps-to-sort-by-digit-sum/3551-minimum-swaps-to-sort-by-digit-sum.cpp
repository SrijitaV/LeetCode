class Solution {
public:
    int minSwaps(vector<int>& nums) {

        vector<int> sum(nums.size());
        vector<tuple<int, int, int>> arr;  // {digit_sum, number, original_index}

        for (int i = 0; i < nums.size(); i++) {
            string num = to_string(nums[i]);
            int add = 0;

            for (int j = 0; j < num.size(); j++) {
                add = add + num[j] - '0';
            }
            
            arr.push_back({add, nums[i], i}); 
        }

        sort(arr.begin(), arr.end());
        vector<bool> visited(nums.size(), false);
        int swaps = 0; 

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] || get<2>(arr[i]) == i)
            {
                continue;                     
            }

            int j = i; 
            int cycle = 0;

            while (!visited[j])
            {
                visited[j] = true; 
                j = get<2>(arr[j]); // humein us element ka original index deta hai
                cycle++;
            }

            swaps = swaps + cycle - 1; 
        }



        return swaps;
    }
};