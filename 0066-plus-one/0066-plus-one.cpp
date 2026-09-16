class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 1) { // for single digit number
            if (digits[0] == 9) {
                return {1, 0};
            } else {
                digits[0]++;
                return digits;
            }
        } else { // for more than or equal to two digits number
            int carry = 1;
            for (int i = digits.size() - 1; i >= 0; i--) {
                // What happens if digits[i] is 9?
                if (digits[i] == 9) {
                    digits[i] = 0;
                    carry = 1;
                }
                // What happens if digits[i] is NOT 9?
                else { // if (digits[i] != 9)
                    digits[i] = digits[i] + carry;
                    carry = 0;
                    break;
                }
            }
            if (carry == 1) {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }

    //     Time: O(n)
    // Auxiliary Space: O(1)
};
