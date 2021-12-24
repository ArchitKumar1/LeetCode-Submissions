// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rm = m;
        int rn = n;
        for(auto x : ops){
            if(rm > x[0]) rm = x[0];
            if(rn > x[1]) rn = x[1];
        }
        return rm*rn;
    }
};