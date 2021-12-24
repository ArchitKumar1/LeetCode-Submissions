// https://leetcode.com/problems/stone-game-v

class Solution {
public:
    vector<int> SV;
    vector<int> prefSum;
    int n ;
    
    int gsum(int i,int j){
        return prefSum[j+1] - prefSum[i];
    }
    
    int solve(int i,int j){
        if(i==j ) return 0;
        
        int ans = 0;
        for(int k = i;k < j;k++){
            int l = gsum(i,k);
            int r = gsum(k+1,j);
            
            //[i][k] + [k+1][j];
            
            if(l < r){
                ans = max(ans,l+solve(i,k));
            }else if(r < l){
                ans = max(ans,r+solve(k+1,j));
            }else {
                ans = max(ans,max(l+solve(i,k),r+solve(k+1,j)));
            }
        }
        return ans;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        SV = stoneValue;
        n = SV.size();
        prefSum.push_back(0);
        for(int c : SV){
            prefSum.push_back(c + prefSum.back());
        }
        return solve(0,n-1);
        
    }
};