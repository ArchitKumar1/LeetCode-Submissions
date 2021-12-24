// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int n;
    int dp[55][55][110];
    vector<vector<int>> C;
    int get(int a,int b,int i){
        if(dp[a][b][i] !=0) return dp[a][b][i];
        int cost =0;
        if(i == n){
            return 0;
        }
        if(a == n/2){
            return dp[a][b][i] = C[i][1] + get(a,b+1,i+1);
        }else if(b == n/2){
            return dp[a][b][i] = C[i][0] + get(a+1,b,i+1);
        }else{
            return dp[a][b][i] = min(C[i][1] + get(a,b+1,i+1),C[i][0] + get(a+1,b,i+1));
        }
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size();
        C = costs;
        return get(0,0,0);
    }
};