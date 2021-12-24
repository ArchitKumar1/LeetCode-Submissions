// https://leetcode.com/problems/maximum-students-taking-exam

class Solution {
public:
    
    
    vector<vector<char>>S;
    int n,m;
    int M ;
    
    vector<vector<int>> dp;
    bool check_mask(int mask){
        for(int i =0;i+1<m;i++){
            int f =( mask&(1<<i)) >=1;
            int s = (mask&(1<<(i+1))) >=1;    
            if(f&s) return 0;
        }
        return 1;
    }
    vector<int> get_all_masks(int pos){
        vector<int> masks;
        
        for(int i = 0;i<M;i++){
            bool safe = 1;
            for(int j=0;j<m;j++){
                if(i&(1<<j) && S[pos][j] == '#'){
                    safe = 0;
                }
            }
            if(safe && check_mask(i)) masks.push_back(i);
        }
        return masks;
    }
    bool intersafe(int m1,int m2){
        for(int i = 0;i+1<m;i++){
            int upleft = (m1&(1<<(i+1))) >=1;
            int curr = (m2&(1<<i)) >=1;
            if(curr && upleft) return 0;
        }
        for(int i = m-1;i>0;i--){
            int upright = (m1&(1<<(i-1))) >=1;
            int curr = (m2&(1<<i)) >=1;
            if(curr && upright) return 0;
        }
        return 1;
    }
    int comp(int m1,int m2){
        return  __builtin_popcount(m1);
    }
    int solve(int pos = 0,int mask = 0){
        
        if(pos == n){
            return 0;
        }
        if(dp[pos][mask] != -1){
            return dp[pos][mask];
        }
        int &ans = dp[pos][mask];
        vector<int> masks = get_all_masks(pos);
        
        for(int m : masks){
            if(intersafe(m,mask)){
                ans = max(ans,comp(m,mask) + solve(pos+1,m));
            }
        }
        return ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        S = seats;
        n = seats.size();
        m = seats[0].size();
        M = (1 << m);
        int ans = 0;
        vector<int> masks1 = get_all_masks(0);
        for(int m :masks1){
            dp.clear();
            dp = vector<vector<int>>(n+1,vector<int>(M+1,-1));
                                     
            ans = max(ans,solve(0,m));
        }
        return ans;
        // [[".",".",".",".",".","."],[".",".",".",".",".","."],[".",".",".",".",".","."]]

    }
};