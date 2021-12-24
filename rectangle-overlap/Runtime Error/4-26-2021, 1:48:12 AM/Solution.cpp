// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& x, vector<int>& y) {
        
        bool ok = 0;
        ok |= (x[2] > y[0] && x[3] > y[1] && x[0] < y[2] && x[1] < y[3]);
        swap(x,y);
        ok |= (x[2] > y[0] && x[3] > y[1] && x[0] < y[2] && x[1] < y[3]);
        vector<int> a = {x[0],x[2],y[0],y[2]};
        vector<int> b = {x[1],x[3],y[1],y[3]};
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int area = abs(a[1]-a[2]) * abs(b[1]-b[2]);
        return ok && area > 0;
    }
};