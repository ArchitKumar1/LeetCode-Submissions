// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int mme = 0;
        int s = 0;
        for(auto p : tasks){
            mme= max(mme,p[1]);
            s += p[0];
        }
        return max(s,mme);
    }
};