class Solution {
// private:
//     int gcd(int a, int b)
//     {
//         if(b == 0)
//             return a; 

//         return gcd(b, a%b);
//     }
// public:
//     int gcdOfOddEvenSums(int n) {
//         int odd = 0, even = 0; 
//         for (int i = 1; i < (n * 2); i++)
//         {
//             if((i % 2) == 0)
//                 even += i;
//             else
//                 odd += i;
//         }
//         return gcd(odd, even);
    // }

public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};