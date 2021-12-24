// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    bool isin(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n,vector<int> (m,0));
        vector<vector<int>> vis(n,vector<int> (m,0));   
        
        
        set<pair<int,pair<int,int>>> qq;
        if(grid[0][0]!=1)qq.insert({1,{0,0}});
        while(qq.size()){   
            auto curr = *qq.begin();
            qq.erase(qq.begin());
            int dist = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            cout << x << " " << y << " " <<dist << endl;
            distance[x][y] = dist;
            
            vis[x][y] = 1;
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                    if(i == 0 && j == 0) continue;
                    int X = x + i;
                    int Y = y + j;
                    if(!isin(X,Y,n,m)) continue;
                    if(vis[X][Y] == 1)continue;
                    if(grid[X][Y] == 1) continue;
                    qq.insert({1+dist,{X,Y}});
                }
            }
        }
        if(vis[n-1][m-1] == 1){
            return distance[n-1][m-1];
        }else{
            return -1;
        }
    }
};