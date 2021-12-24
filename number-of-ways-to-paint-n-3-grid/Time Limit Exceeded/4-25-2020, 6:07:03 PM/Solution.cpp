// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

class Solution {
public:
    int solve(int x,int y,int z,int n){
        int ans =0 ;
        if(n == 0) return 1;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                for(int k = 0;k<3;k++){
                    if(i == x || j == y || k == z){
                        continue;
                    }
                    if(i == j || j == k) continue;
                    ans += solve(i,j,k,n-1);
                }
            }
        }
        return ans;
    }
    
    int numOfWays(int n) {
        
        int ans = 0;
        
        return solve(-1,-1,-1,n);
        
    }
};