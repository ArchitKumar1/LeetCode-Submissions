// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = INT_MAX;
        int val = 0;
        for(int y = 2050;y>=1950;y--){
            int count = 0;
            for(auto x : logs){
                if(y >= x[0] && y < x[1]){
                    count++;
                }
            }
            if(count >= val){
                val = count;
                ans = y;
            }
        }
        return ans;
    }
};