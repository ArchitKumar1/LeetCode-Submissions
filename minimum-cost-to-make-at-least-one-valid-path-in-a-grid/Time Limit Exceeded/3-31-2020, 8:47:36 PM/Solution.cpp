// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
public:
    struct s{
        int c,x,y;
        bool operator>(const s &o) const{
            return c > o.c;
        }
        bool operator<(const s &o) const{
            return c < o.c;
        }
    };
    
    int minCost(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        priority_queue<s,vector<s>,greater<s>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({0,0,0});
        while(pq.size()){
            s t = pq.top();
            pq.pop();
            vis[t.x][t.y] = 1;
            if(t.x == n-1 && t.y == m-1){
                return t.c;
            }
            for(int i = 0;i<4;i++){
                int X = t.x + dir[i][0];
                int Y = t.y + dir[i][1];
                if(X < 0 || Y<0 ||X>=n|Y>=m) continue;
                if(i == g[t.x][t.y]-1){
                    pq.push({t.c,X,Y});
                }else{
                    pq.push({t.c+1,X,Y});
                }
            }
        }
        return -1;
    }
};