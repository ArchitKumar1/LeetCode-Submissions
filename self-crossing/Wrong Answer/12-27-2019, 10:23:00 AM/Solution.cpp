// https://leetcode.com/problems/self-crossing

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        return ((x[2] - x[0])<=0);
    }
};