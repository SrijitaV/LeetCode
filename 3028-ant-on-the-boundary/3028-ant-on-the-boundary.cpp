class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0; 
        int answer = 0; 

        for (int i = 0; i < nums.size(); i++)
        {
            position = position + nums[i];

            if (position == 0)
            {
                answer++;
            }
        }

        return answer; 
    }
};