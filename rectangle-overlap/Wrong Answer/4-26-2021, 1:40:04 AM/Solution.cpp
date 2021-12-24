// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& x, vector<int>& y) {
        
        bool ok = 0;
        ok |= (x[2] > y[0] && x[3] > y[1]);
        swap(x,y);
        ok |= (x[2] > y[0] && x[3] > y[1]);
        return ok;
    }
};