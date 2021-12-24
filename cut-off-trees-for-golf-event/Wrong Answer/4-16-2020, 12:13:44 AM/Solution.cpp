// https://leetcode.com/problems/cut-off-trees-for-golf-event

class Solution {
public:
    struct p{
        int x,y,cnt;
    };
    int cutOffTree(vector<vector<int>>& f) {
        int n = f.size();
        int m = f[0].size();
        
        queue<p> qq;
        qq.push({0,0,0});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;

        int ans = 0;
        
        while(qq.size()){
            for(int i = 0;i<qq.size();i++){
                p t = qq.front();qq.pop();
                ans = max(ans,t.cnt);
                cout << t.x << " " << t.y << " " << t.cnt << endl;
                vis[t.x][t.y] = 1;
                for(int x = -1;x<=1;x++){
                    for(int y = -1;y<=1;y++){
                        if((x*x + y*y) == 1){
                            int X = t.x + x;
                            int Y = t.y + y;
                            if( X < 0 || Y <0 || X >=n || Y >=m || f[X][Y] == 0 || vis[X][Y] ==1 ){
                                continue;
                            }
                            if(f[X][Y] > f[t.x][t.y]){
                                qq.push({X,Y,t.cnt+1});
                            }else{
                                qq.push({X,Y,t.cnt});
                            }
                        }
                    }
                }
            }
        }
        bool ok = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(f[i][j] != 0 && vis[i][j] == 0) ok = 0;
            }
        }
        return ((ans == 0 || ok == 0)? -1 :ans);
    }
};