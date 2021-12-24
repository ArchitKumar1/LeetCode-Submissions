// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto x : grid){
            for(auto y : x){
                if(y < 0)cnt+=1;
            }
        }
        return cnt;
    }
};