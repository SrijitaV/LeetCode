class Solution {
public:
    int pivotInteger(int n) {
    //             TWO POINTER 
        // if (n == 1)
        //     return 1;
        // int low = 1, high = n;
        // int lowsum = 0, highsum = 0;
        // // lowsum = lowsum + low;
        // // low++;
        // // highsum = highsum + high;
        // // high--;
        // while (low <= high) {
        //     if (lowsum <= highsum) {
        //         lowsum = lowsum + low;
        //         low++;
        //     } else { // (lowsum > highsum)
        //         highsum = highsum + high;
        //         high--;
        //     }
        //     if ((lowsum == highsum) && (low == high)) {
        //         return high;
        //     }
        // }
        // return -1;

    //             SQUARE ROOT ~ SUM OF N NATURAL NUMBERS 
        int total = (n * (n + 1)) / 2; 
        int x = sqrt(total); 
        if ((x * x) == total)
            return x; 
        return -1;
    }
};