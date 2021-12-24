// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> sums;
        int n= grid.size(),m = grid[0].size();
        auto check = [&](int x ,int y) -> bool{
            return x>=0 && y >=0 && x < n && y < m;
        };
        int dx[4] = { 1 ,1 ,-1,-1};
        int dy[4] = { -1 ,1 ,1,-1};
        auto comp = [&](int a,int b,int c,int d,int t) -> int{
            int ans = 0;
            while(a != c && b!= d){
                ans += grid[a][b];
                a += dx[t];
                b += dy[t];
            }
            return ans;
        };
        for(int i = 0;i <n;i++){
            for(int j = 0;j <m;j++){
                sums.insert(grid[i][j]);
                int lx =i,ly = j;
                int rx =i,ry = j;
                int dx = i;
                bool done = true;
                while(done){
                    lx++,ly--;
                    if(!check(lx,ly)) done = false;
                    rx++,ry++;
                    if(!check(rx,ry)) done = false;
                    dx+= 2;
                    if(!check(dx,j)) done = false;
                    if(done == true){
                        int tans = 0;
                        tans += comp(i,j,lx,ly,0);
                        tans += comp(lx,ly,dx,j,1);
                        tans += comp(dx,j,rx,ry,2);
                        tans += comp(rx,ry,i,j,3);
                        sums.insert(tans);
                    }
                }
            }
        }
        vector<int> res;
        for(auto x : sums){
            res.push_back(x);
        }
        reverse(res.begin(),res.end());
        if(res.size() > 3)
        res.resize(3);
        return res;
    }
};