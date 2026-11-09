class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // A variable k is initialized to 0.
        // k will be used to keep track of the position
        // in the list where the next element that is
        // not equal to val should be placed.
        int k = 0;

        // Loop through the List
        for (int i = 0; i < nums.size(); i++) {

            // checks if the current element nums[i] is not equal to val.
            // If the condition is true,
            // it means the element should be kept in the list.
            if (nums[i] != val) {

                // If the current element nums[i] is not equal to val,
                // it is assigned to the position k in the list.
                // This effectively moves the element to
                // the next available position for elements that are not val.
                nums[k] = nums[i];

                // k is incremented by 1.
                // This prepares k to point to the
                // next position for the next element that is not equal to val.
                k++;
            }
        }

        // returns the value of k.
        // k represents the number of elements
        // in the list that are not equal to val.
        return k;

        // Time complexity: O(n)
        // Space complexity: O(1)
    }
};

/*
Intution Summary :

- The function iterates through the list, checking each element.
- If an element is not equal to the specified value (val), it is moved to the
front of the list, and k is incremented.
- The function finally returns k, which is the count of elements that are not
equal to val.

This algorithm modifies the list in-place and ensures that the first k elements
of nums contain the elements that are not equal to val.
*/