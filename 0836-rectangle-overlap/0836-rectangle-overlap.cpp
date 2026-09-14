class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        // rec[0] = x1 = left
        // rec[1] = y1 = bottom
        // rec[2] = x2 = right
        // rec[3] = y2 = top

        //                 y
        //         ↑
        //         |
        //  (x1,y2) ●──────────────● (x2,y2)
        //           │              │
        //           │              │
        //           │   RECTANGLE  │
        //           │              │
        //           │              │
        //  (x1,y1) ●──────────────● (x2,y1)
        //         |
        //         └────────────────────────→ x

        // check if either rectangle is actually a line
        // if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] ||
        //     rec2[1] == rec2[3]) {
        //     // the line cannot have positive overlap
        //     return false;
        // }

        // R1 is left of R2 OR R1 is below R2 OR R1 is right of R2 OR R1 is
        // above R2.   If any one of these is true, there is no overlap.    NO
        // OVERLAP
        return !(
            rec1[2] <= rec2[0] || // left   // Case 1: Rectangle 1 is completely
                                  // to the LEFT of Rectangle 2   // right edge
                                  // of R1 <= left edge of R2
            rec1[3] <=
                rec2[1] || // bottom   // Case 2: Rectangle 1 is completely
                           // BELOW Rectangle 2   // top of R1 <= bottom of R2
            rec1[0] >=
                rec2[2] || // right  // Case 3: Rectangle 1 is completely to the
                           // RIGHT of Rectangle 2  // left of R1 >= right of R2
            rec1[1] >=
                rec2[3]); // top  // Case 4: Rectangle 1 is completely ABOVE
                          // Rectangle 2  // bottom of R1 >= top of R2
    }
};