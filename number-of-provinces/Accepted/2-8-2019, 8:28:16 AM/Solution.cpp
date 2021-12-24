// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(vector<vector<int>> &M,int x,int y){
        if(x>=0 && y>=0 && x<M.size() && y<M[0].size() and M[x][y]==1){
            M[x][y]=0;
            int i=x;
            int j=y;
            for(int i=0;i<M.size();i++){
                if(i!=x) dfs(M,i,y);
            }
            for(int j=0;j<M[0].size();j++){
                if(j!=y) dfs(M,x,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int regions=0;
        for(auto i=0;i<M.size();i++){
            for(auto j=0;j<M[0].size();j++){
                if(M[i][j]==1){
                    regions++;
                    dfs(M,i,j);
                }
            }
        }
        return regions;
    }
        
    
};