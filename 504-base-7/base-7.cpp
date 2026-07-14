class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";

        bool neg = num < 0;
        num = abs(num);

        int ans = 0;
        int place = 1; 
        while (num > 0)  
        { 
            int rem = num % 7;
            ans = ans + rem * place;
            place = place * 10;
            num = num / 7; 
        }

        string answer = to_string(ans);

        if (neg)
        answer = "-" + answer;

        return answer;
    }
};