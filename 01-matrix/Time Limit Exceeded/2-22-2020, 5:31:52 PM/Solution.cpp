// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        queue<pair<int,pair<int,int>>> q;
        for(int i =0 ;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        while(q.size()){
            pair<int,pair<int,int>> temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            int dist = temp.first;
            cout << x << " " << y << " " << dist << endl;
            if(x<0 || x>n-1 || y < 0 || y>m-1 || vis[x][y]) {
                continue;
            }
            vis[x][y] = 1;
            ans[x][y] = dist;
            cout << x << " " << y << " " << dist << endl;
            q.push({dist+1,{x+1,y}});
            q.push({dist+1,{x-1,y}});
            q.push({dist+1,{x,y-1}});
            q.push({dist+1,{x,y+1}});
        }
        return ans;
    }
};