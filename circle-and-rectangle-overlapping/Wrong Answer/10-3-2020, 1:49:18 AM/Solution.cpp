// https://leetcode.com/problems/circle-and-rectangle-overlapping

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int xcma = x_center + radius;
        int xcmi = x_center - radius;
        int ycma = y_center + radius;
        int ycmi = y_center - radius;
        
        bool in = 0;
        bool in2 = 0;
        if(x1 >=xcmi && x1 <=xcma) in = 1;
        if(x2 >=xcmi && x2 <=xcma) in = 1;
        if(y1 >=ycmi && y1 <=ycma) in2 = 1;
        if(y2 >=ycmi && y2 <=ycma) in2 = 1;
        return in&in2;
    }
};