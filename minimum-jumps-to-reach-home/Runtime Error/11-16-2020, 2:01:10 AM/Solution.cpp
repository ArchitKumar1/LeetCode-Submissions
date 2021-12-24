// https://leetcode.com/problems/minimum-jumps-to-reach-home

class Solution {
    

public:
    map<int,int> m1;
    vector<int> dp;
    int a,b,x;
    int INF = 1e9;
    int solve(int pos,int last){
        
        cout << pos << endl;
        if(pos == x) return 0;
        if(pos > 2000) return 1e9;
        if(pos < 0) return 1e9;
        if(m1[pos] == 1) return 1e9;
        
        if(dp[pos]!= -1) return dp[pos];
        
        int ans = 1e9;
        ans = min(ans,1+solve(pos+a,0));
        if(last != 1) ans = min(ans,1+solve(pos-b,0));
        return dp[pos] = ans;
    }
    
    int minimumJumps(vector<int>& forbidden, int A, int B, int X) {
        a = A,b=B,x=X;
        int N = 300000;
        dp.assign(N,-1);
        for(int c :forbidden )m1[c]++;
        return solve(0,0);
    
        
    }
};