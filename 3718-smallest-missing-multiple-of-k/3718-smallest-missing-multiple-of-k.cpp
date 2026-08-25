class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // nums[i] <= 100, so we need indices from 0 to 100.
        // Hence, size 101 is enough to store the presence of all input values.
        // However, the answer can be greater than 100.
        // For example, if all multiples of 2 from 2 to 100 are present,
        // the smallest missing multiple is 102.
        // Therefore, we check `multiple > 100` before accessing
        // present[multiple]. In general, the answer can be greater than the
        // maximum value in nums.
        vector<bool> present(201, false);
        for (int i = 0; i < nums.size(); i++) {
            present[nums[i]] = true;
        }
        for (int i = k; i < 201; i += k) {
            if (!present[i])
                return i;
        }
        return -1;
    }
};