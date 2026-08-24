class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1)
            return 1;
        int low = 1, high = n;
        int lowsum = 0, highsum = 0;
        // lowsum = lowsum + low;
        // low++;
        // highsum = highsum + high;
        // high--;
        while (low <= high) {
            if (lowsum <= highsum) {
                lowsum = lowsum + low;
                low++;
            } else { // (lowsum > highsum)
                highsum = highsum + high;
                high--;
            }
            if ((lowsum == highsum) && (low == high)) {
                return high;
            }
        }
        return -1;
    }
};