// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        auto area = [&](int x, int y1, int x2, int y2){
            return (x2-x1) * (y2-y1);
        };
        bool X = false,Y = false;
        if((bx1 < ax1 && ax1 < bx2) || (ax1 < bx1 && bx1 < ax2)) X = true;
        if((by1 < ay1 && ay1 < by2) || (ay1 < by1 && by1 < ay2)) Y = true;
        
        bool overlap = X & Y;
        
        int total = area(ax1, ay1,  ax2,  ay2) + area(bx1, by1,  bx2,  by2);
        if(!overlap) return total;
        
        vector<int> x = {ax1,ax2,bx1,bx2};
        vector<int> y = {ay1,ay2,by1,by2};
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        return total - area(x[1],y[1],x[2],y[2]);
    }
};