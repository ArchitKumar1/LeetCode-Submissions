// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& x, vector<int>& y) {
        
        bool ok = 0;
        ok |= (x[2] > y[0] && x[3] > y[1] && x[0] < y[2] && x[1] < y[3]);
        swap(x,y);
        ok |= (x[2] > y[0] && x[3] > y[1] && x[0] < y[2] && x[1] < y[3]);
        return ok;
    }
};