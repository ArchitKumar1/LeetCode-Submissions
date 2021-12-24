// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    
    struct s{
        int i,j,k = 0;
        
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        bool found = 0;
        
        queue<s> qq;
        s start;
        start.i = 0,start.j = 0;
        qq.push(start);
        
        int dx[4] ={1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        
        int vis[n][m] ;
        memset(vis,0,sizeof(vis));
        
        while(qq.size()){
            int sz = qq.size();
            
            for(int i = 0;i<sz;i++){
                s top = qq.front();qq.pop();
                
                if(top.i < 0 || top.j < 0 || top.i > n-1 || top.j > m-1) continue;
                
                if(vis[top.i][top.j] == 1) continue;
                vis[top.i][top.j] = 1;
                
                if(grid[top.i][top.j] == 1) top.k++;
                if(top.k > k) continue;
                                
                cout << "standard" << top.i << " " << top.j << top.k << endl;
                if(top.i == n-1 && top.j == m-1){
                    cout << "MILA" << top.i << " " << top.j << endl;
                    found = 1;
                    qq = queue<s>();
                    break;
                } 
                for(int k = 0;k<4;k++){
                    int ii = top.i + dx[k];
                    int jj = top.j + dy[k];
                    
                    s newtop;
                    newtop.i = ii,newtop.j = jj,newtop.k = top.k;
                    qq.push(newtop);
                    
                }
            }
            ans += 1;
        }
        return !found?-1:ans-1;
    }
};