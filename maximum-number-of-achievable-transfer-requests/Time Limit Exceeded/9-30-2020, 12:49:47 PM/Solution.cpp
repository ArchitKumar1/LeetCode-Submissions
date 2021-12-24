// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests

class Solution {
public:
    vector<vector<int>>R;
    int N;
    
    int solve(int r, vector<int>mask){
        
        if(r == N){
            int safe = 1;
            for(int c : mask) if(c !=0) safe = 0;
            if(safe==1) return 0;
            else return -1e9;
        }
        int ans = -1e9;
        int f = R[r][0];
        int s = R[r][1];
        ans = max(ans,solve(r+1,mask));
        mask[f]--;
        mask[s]++;
        ans = max(ans,1+solve(r+1,mask));
        return ans;
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        N = requests.size(), R = requests;
        return solve(0,vector<int>(n,0));
    }
};