class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // We create two arrays:
        //     1. prefixMax
        //     2. suffixMin
        // prefixMax[i] stores:
        //     maximum value from nums[0] to nums[i]
        // suffixMin[i] stores:
        //     minimum value from nums[i] to nums[n-1]
        // Then for any index i:
        //     maxi = prefixMax[i]
        //     mini = suffixMin[i]
        //     score = maxi - mini
        // So we don't need to scan nums again for every index.

        int n = nums.size();

        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        // Build prefix maximum
        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        // Build suffix minimum
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        // Check every index
        for (int i = 0; i < n; i++) {

            int maxi = prefixMax[i];
            int mini = suffixMin[i];

            int score = maxi - mini;

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
/*
    ------------------------------------------------------------
        TIME COMPLEXITY:
    ------------------------------------------------------------

        Building prefixMax:  O(n)
        Building suffixMin:  O(n)
        Checking indices:     O(n)

        Total:

            O(n) + O(n) + O(n)
            = O(n)

        ------------------------------------------------------------
        SPACE COMPLEXITY:
        ------------------------------------------------------------

        prefixMax array: O(n)
        suffixMin array:  O(n)

        Total auxiliary space:

            O(n)

        ------------------------------------------------------------
        KEY PATTERN TO REMEMBER:
        ------------------------------------------------------------

        If a problem repeatedly asks for:

            maximum from beginning -> current index

        Think:

            PREFIX MAX


        If a problem repeatedly asks for:

            minimum from current index -> end

        Think:

            SUFFIX MIN


        Here:

            instability score
            = prefixMax[i] - suffixMin[i]

        This changes the original O(n^2) solution into an O(n)
        solution, which is necessary because n can be 100,000.

        ------------------------------------------------------------
        */
};
/*

  ------------------------------------------------------------
        EXAMPLE:
        ------------------------------------------------------------

        nums = [5, 0, 1, 4]
        k = 3

        PREFIX MAX:

        prefixMax[i] = maximum from index 0 to i

        i = 0:
            max([5]) = 5

        i = 1:
            max([5,0]) = 5

        i = 2:
            max([5,0,1]) = 5

        i = 3:
            max([5,0,1,4]) = 5

        Therefore:

            nums:       [5, 0, 1, 4]
            prefixMax:  [5, 5, 5, 5]


        SUFFIX MIN:

        suffixMin[i] = minimum from index i to n-1

        i = 3:
            min([4]) = 4

        i = 2:
            min([1,4]) = 1

        i = 1:
            min([0,1,4]) = 0

        i = 0:
            min([5,0,1,4]) = 0

        Therefore:

            nums:       [5, 0, 1, 4]
            suffixMin:  [0, 0, 1, 4]


        Now we can calculate the score for every index:

            i = 0:
                prefixMax[0] - suffixMin[0]
                = 5 - 0
                = 5

            i = 1:
                prefixMax[1] - suffixMin[1]
                = 5 - 0
                = 5

            i = 2:
                prefixMax[2] - suffixMin[2]
                = 5 - 1
                = 4

            i = 3:
                prefixMax[3] - suffixMin[3]
                = 5 - 4
                = 1

        Since k = 3, we need score <= 3.

            i = 0 -> 5 <= 3 -> FALSE
            i = 1 -> 5 <= 3 -> FALSE
            i = 2 -> 4 <= 3 -> FALSE
            i = 3 -> 1 <= 3 -> TRUE

        Therefore, the smallest stable index is 3.

        ------------------------------------------------------------
        BUILDING PREFIX MAX:
        ------------------------------------------------------------

        prefixMax[0] is simply nums[0].

        For every next index i:

            prefixMax[i] =
                max(prefixMax[i-1], nums[i])

        Why?

        prefixMax[i-1] already contains the maximum value
        from nums[0] to nums[i-1].

        We only need to compare that maximum with nums[i].

        Example:

            prefixMax[1] = max(prefixMax[0], nums[1])
                         = max(5, 0)
                         = 5

            prefixMax[2] = max(prefixMax[1], nums[2])
                         = max(5, 1)
                         = 5

        This allows us to build prefixMax in O(n).

        ------------------------------------------------------------
        BUILDING SUFFIX MIN:
        ------------------------------------------------------------

        suffixMin[n-1] is simply nums[n-1].

        We move from RIGHT TO LEFT because suffixMin[i]
        depends on the values to the RIGHT of i.

        For every index i:

            suffixMin[i] =
                min(nums[i], suffixMin[i+1])

        Why?

        suffixMin[i+1] already contains the minimum value
        from nums[i+1] to nums[n-1].

        We only need to compare that with nums[i].

        Example:

            suffixMin[2] = min(nums[2], suffixMin[3])
                         = min(1, 4)
                         = 1

            suffixMin[1] = min(nums[1], suffixMin[2])
                         = min(0, 1)
                         = 0

        This also takes O(n).

        ------------------------------------------------------------
        FINAL CHECK:
        ------------------------------------------------------------

        Once prefixMax and suffixMin are built:

            maxi = prefixMax[i]
            mini = suffixMin[i]

        Both are O(1) lookups.

        Therefore:

            score = prefixMax[i] - suffixMin[i]

        If score <= k:
            return i

        We check from left to right, so the first stable index
        we find is automatically the SMALLEST stable index.
*/