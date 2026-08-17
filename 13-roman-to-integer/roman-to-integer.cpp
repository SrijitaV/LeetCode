class Solution {
private:
    int char2num(char a) {
        switch (a) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (((i + 1) < s.length()) &&
                ((char2num(s[i])) < (char2num(s[i + 1]))))
                result = result - char2num(s[i]);
            else
                result = result + char2num(s[i]);
        }
        return result;

        // int sum = 0;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (s[i] == 'I')
        //         sum = sum + 1;
        //     else if (s[i] == 'V')
        //         sum = sum + 5;
        //     else if (s[i] == 'X')
        //         sum = sum + 10;
        //     else if (s[i] == 'L')
        //         sum = sum + 50;
        //     else if (s[i] == 'C')
        //         sum = sum + 100;
        //     else if (s[i] == 'D')
        //         sum = sum + 500;
        //     else    // s[i] == 'M'
        //         sum = sum + 1000;
        // }
        // return sum;
    }
};