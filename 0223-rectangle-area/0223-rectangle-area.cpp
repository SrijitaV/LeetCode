class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA, areaB, commonWidth, commonHeight, commonArea;

        // seperate area of both the rectangles 
        areaA = (ax2 - ax1) * (ay2 - ay1);
        areaB = (bx2 - bx1) * (by2 - by1);

        // Two rectangles overlap only where their ranges overlap.
        // So we need to find: common X range, common Y range
        // Then: Common Area = Common Width * Common Height
        commonWidth = max(0, min(ax2, bx2) - max(ax1, bx1));
        commonHeight = max(0, min(ay2, by2) - max(ay1, by1));
        commonArea = commonWidth * commonHeight;

        return areaA + areaB - commonArea;
    }
};