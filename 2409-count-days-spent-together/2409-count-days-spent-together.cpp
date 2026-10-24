class Solution {
private:
    int getDay(string date) {

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = day;

        for (int i = 0; i < month - 1; i++) {
            total = total + days[i];
        }

        return total;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        // given
        // 4 strings ~ arriveAlice, leaveAlice, arriveBob, and leaveBob
        // Alice will be in the city from the dates arriveAlice to leaveAlice
        // while Bob will be in the city from the dates arriveBob to leaveBob
        // both dates inclusive
        // Each will be a 5-character string in the format "MM-DD",
        // corresponding to the month and day of the date

        // Return the total number of days that Alice and Bob
        // are in Rome together.

        // assume that all dates occur in the same calendar year,
        // which is not a leap year.
        // Note that the number of days per month can be represented as:
        // [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        // -------------- my brute force approach ------------------

        int a1 = getDay(arriveAlice);
        int a2 = getDay(leaveAlice);
        int b1 = getDay(arriveBob);
        int b2 = getDay(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (start > end) {
            return 0;
        }

        return end - start + 1;

        // Time Complexity: O(1)
        // ~ because there are only 12 months and four dates.
        // Space Complexity: O(1)
        // ~ because we use a fixed-size array and a few variables.
    }
};