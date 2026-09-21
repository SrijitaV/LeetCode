class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0; 
        int answer = 0; 

        // That boundary is basically a fixed line separating the left and right sides.
        // We can choose to represent that line using the number: 0
        // means:The ant is exactly on the boundary.
        // The number tells us exactly where the ant is relative to the boundary.

        // We don't need to create or check a physical boundary. We represent the boundary as coordinate 0, and represent the ant's location as position. Therefore, position == 0 is literally the boundary check.

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
 
    // Time: O(n)    ~ 	  Traverse nums once
    // Space: O(1)	 ~    Only position and answer are used
};