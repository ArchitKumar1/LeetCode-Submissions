// https://leetcode.com/problems/regions-cut-by-slashes

class Solution {
    
public:
    int n,m,M;
    vector<int> par;
    int cnt ;
    int getid(int i,int j,int k){
        k--;
        return 4*(n*i+j) + k;
    }
    int get(int v){
        if(par[v] == v){
            return v;
        }else{
            return par[v] = get(par[v]);
        }
    }
    void merge(int a,int b){
        a = get(a);
        b = get(b);
        if(a  == b)return ;
        par[a] = b;
        cnt--;
    }
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        M = n*n*4;
        cnt = M;
        par.assign(M,0);
        
        for(int i = 0;i<M;i++){
            par[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i > 0) merge(getid(i,j,1),getid(i-1,j,3));
                if(i > 0) merge(getid(i,j,2),getid(i,j-1,4));
                
                if(grid[i][j] == '\\'){
                    merge(getid(i,j,1),getid(i,j,4));
                    merge(getid(i,j,2),getid(i,j,3));
                }else if(grid[i][j] == '/'){
                    merge(getid(i,j,1),getid(i,j,2));
                    merge(getid(i,j,3),getid(i,j,4));
                }else{
                    merge(getid(i,j,1),getid(i,j,2));
                    merge(getid(i,j,2),getid(i,j,3));
                    merge(getid(i,j,3),getid(i,j,4));
                }
            }
        }
        return cnt;
        
        
        
    }
};