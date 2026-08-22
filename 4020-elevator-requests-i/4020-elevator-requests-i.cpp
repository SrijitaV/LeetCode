class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int totaltime = 0;
        int prev = 0; 
        for (int i = 0; i < requests.size(); i++) {
            totaltime = totaltime + abs(prev - requests[i]); 
            prev = requests[i]; 
        }
        return totaltime; 
    }
};