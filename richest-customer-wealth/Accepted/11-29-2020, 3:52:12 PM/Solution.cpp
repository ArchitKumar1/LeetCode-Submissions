// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int fans = 0;
        for(auto x :accounts ){
            int tans = 0;
            for(auto y : x){
                tans += y;
            }
            fans = max(fans,tans);
        }
        return fans;
    }
};