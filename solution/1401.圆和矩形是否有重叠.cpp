//枚举：暴力枚举圆中每个横纵坐标为整数的坐标，若圆和矩形相交，则一定有这样的坐标在矩形内
class Solution {
  public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for (int x = xCenter - radius; x <= xCenter + radius; x++)
            for (int y = yCenter - radius; y <= yCenter + radius; y++)
                if (pow(x - xCenter, 2) + pow(y - yCenter, 2) <= pow(radius, 2) && x1 <= x && x <= x2 && y1 <= y && y <= y2)
                    return true;
        return false;
    }
};