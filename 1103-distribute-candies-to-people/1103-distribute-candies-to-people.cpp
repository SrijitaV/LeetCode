class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int i = 0;
        int counter = 1;
        while (candies > 0) {
            if (candies >= counter) {
                ans[i] += counter;
                candies -= counter;
            } else {
                ans[i] += candies;
                candies = 0;
            }

            counter++;
            if (i == num_people - 1) {
                i = 0;
            } else {
                i++;
            }
        }
        return ans;
    }
};

// i = (i + 1) % num_people;