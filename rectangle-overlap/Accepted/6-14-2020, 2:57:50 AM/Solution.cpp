// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool ok = rec1[2] > rec2[0] && rec1[3] > rec2[1] && rec1[0] < rec2[2] && rec1[1] < rec2[3];
        swap(rec1,rec2);
        ok |= rec1[2] > rec2[0] && rec1[3] > rec2[1] && rec1[0] < rec2[2] && rec1[1] < rec2[3];
        return ok;
    }
};