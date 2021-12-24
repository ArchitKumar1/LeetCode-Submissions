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
        
        
        queue<pair<int,pair<int,int>>> qq;
        qq.push({0,{0,0}});
        while(qq.size()){   
            auto curr = qq.front();
            qq.pop();
            int dist = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            distance[x][y] = dist;
            if(vis[x][y] == 1) continue;
            vis[x][y] = 1;
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                    if(i == 0 && j == 0) continue;
                    int X = x + i;
                    int Y = y + j;
                    if(!isin(X,Y,n,m)) continue;
                    qq.push({1+dist,{X,Y}});
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