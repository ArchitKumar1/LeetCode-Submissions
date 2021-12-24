// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        int ans = 0;
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        vis[e[0]][e[1]] = 1;
        bool f = 0;
        int cnt = 0;
        
        while(q.size()){
            cnt++;
            cout << cnt <<" " <<  q.size() << endl;
            int l = q.size();
            for(int i = 0;i < l;i++){
                auto p = q.front(); q.pop();
                int x = p.first,y = p.second;
                vis[x][y] = 1;
                //cout << x << ":" << y << endl;
                if( x == 0 || y == 0 || x == (n-1) || y == (m-1)){
                   if(!(x == e[0] && y == e[1])){
                        q = queue<pair<int,int>>();
                        f = 1;
                        break;
                   }
                }
                for(int k = 0;k < 4;k++){
                    int X = x + dx[k];
                    int Y = y + dy[k];
                    if( X>=0 && Y>= 0 && X < n && Y < m && maze[X][Y] == '.' && vis[X][Y] == 0){
                        // cout << X << " " << Y << endl;
                        vis[X][Y] = 1;
                        q.push({X,Y});
                    }
                }
            }
            if(f) break;
            ans++;
            //cout << "a++" << endl;
            
        }
        return f == 1 ? ans : -1;
        
    }
};