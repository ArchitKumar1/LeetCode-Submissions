// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int o=0,e=0;
        for(int c : chips){
            if(c&1) o++;
            else e++;
        } 
        return min(o,e);
        
    }
};