// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rm = m;
        int rn = n;
        for(auto x : ops){
            rm = min(x[0],rm);
            rn = min(x[1],rn);
        }
        return rm*rn;
    }
};