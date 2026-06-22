class Solution {
public:
    int addDigits(int num) {
        while (num >= 10)
        {
            int n = 0;
            int sum = 0; 
            while(num >= 1)
            {
                n = num % 10;
                sum = sum + n; 
                num = num / 10; 
            }
            num = sum;
        }

        return num; 
    }
};