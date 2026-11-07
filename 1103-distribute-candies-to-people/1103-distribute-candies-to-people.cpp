
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        // -------------------------- modulo approach --------------------------

        // creating an answer vector of size num_people
        vector<int> ans(num_people);

        int i = 0;       // index to keep track of the person
        int counter = 1; // candies to be distributed in each turn

        while (candies > 0) {

            // checking if enough candies are available
            if (candies >= counter) {

                // adding candies to the current person's total
                ans[i] += counter;

                // reducing remaining candies
                candies -= counter;

            } else {

                // distributing whatever candies are left
                ans[i] += candies;
                candies = 0;
            }

            // increasing candies for the next turn
            counter++;

            // moving to the next person
            // modulo brings us back to index 0 after the last person
            i = (i + 1) % num_people;
        }

        // returning the final distribution
        return ans;

        // Time Complexity ~ O(sqrt{candies})
        // Space Complexity ~ (O(num_people)

        // ------------------------------------------------------------------

        // // -------------------- my brute force approach -------------------
        // // -------------------------- simulation --------------------------

        // // creating an answer vector of size num_people
        // // initially all values will be 0
        // vector<int> ans(num_people);

        // int i = 0;       // index to keep track of the person
        // int counter = 1; // candies to be given in each turn

        // while (candies > 0) {

        //     // checking if we have enough candies to give counter candies
        //     if (candies >= counter) {

        //         // adding candies to the current person's total
        //         ans[i] += counter;

        //         // reducing the remaining candies
        //         candies = candies - counter;

        //     } else {

        //         // if remaining candies are less than counter,
        //         // give whatever candies are left
        //         ans[i] += candies;

        //         // all candies have been distributed
        //         candies = 0;
        //     }

        //     // increasing the number of candies to be given in the next turn
        //     counter++;

        //     // moving to the next person
        //     // if we reach the last person, go back to the first person
        //     if (i == num_people - 1) {
        //         i = 0;
        //     } else {
        //         i++;
        //     }
        // }

        // // returning the final distribution
        // return ans;

        // // Time Complexity: O(sqrt{candies})
        // // Why?
        // // - In every iteration, counter increases by 1.
        // // - We distribute 1, then 2, then 3, then 4, and so on.
        // // - The loop stops when the total distributed candies reach the
        // // available candies. So, after k iterations: 1 + 2 + 3 + ... + k <=
        // // candies Using the sum formula: frac{k(k+1)}{2} <= candies
        // Therefore:
        // // k = O(\sqrt{candies})

        // // Space Complexity: O(num_people)
        // // Why?
        // // - You create an answer vector of size num_people.
        // // - The remaining variables (i, counter) use constant space, O(1).
    }
};
