// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests

class Solution {
public:
    vector<vector<int>>R;
    int N;
    
    int solve(int r,int mask){
        
        if(r == N){
            if(mask == 0) return 0;
            else return -1e9;
        }
        int ans = -1e9;
        int f = R[r][0];
        int s = R[r][1];
        ans = max(ans,solve(r+1,mask));
        mask^=(1<<f);
        mask^=(1<<s);
        ans = max(ans,1+solve(r+1,mask));
        return ans;
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        N = n, R = requests;
        return solve(0,0);
    }
};