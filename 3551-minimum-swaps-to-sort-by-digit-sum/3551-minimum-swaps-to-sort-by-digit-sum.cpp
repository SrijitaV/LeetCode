class Solution {
public:
    int minSwaps(vector<int>& nums) {

        // Step 1: Digit sum nikalna ~ Har number ka digit sum calculate karte
        // hain.
        vector<int> sum(nums.size());
        vector<tuple<int, int, int>> arr; // {digit_sum, number, original_index}

        for (int i = 0; i < nums.size(); i++) {
            string num = to_string(nums[i]);
            int add = 0;

            for (int j = 0; j < num.size(); j++) {
                add = add + num[j] -
                      '0'; // -'0' kyun kiya? Kyunki num[j] character hai, aur
                           // -'0' karne se uska actual numeric digit milta hai.
            }

            arr.push_back(
                {add, nums[i], i}); // Digit sum, number aur original index ko
                                    // ek saath store kar dete hain.
        }

        // Step 2: Sort karna ~ Har number ke saath uska original index bhi
        // store karte hain, taaki pata rahe number pehle kahan tha.
        sort(arr.begin(), arr.end());
        vector<bool> visited(nums.size(), false);
        int swaps = 0;

        // Step 3: Minimum swaps count karna ~ visited array aur cycles ki help
        // se calculate karte hain ki kitne swaps lagenge.
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || get<2>(arr[i]) == i) {
                continue;
            }

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(
                    arr[j]); // humein us element ka original index deta hai
                cycle++;
            }

            swaps = swaps + cycle - 1;
        }

        return swaps;
    }
};