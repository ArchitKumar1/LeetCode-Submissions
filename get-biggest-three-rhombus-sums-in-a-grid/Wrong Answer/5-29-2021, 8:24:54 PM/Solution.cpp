// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> sums;
        int n= grid.size(),m = grid[0].size();
        auto check = [&](int x ,int y) -> bool{
            return x>=0 && y >=0 && x < n && y < m;
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
                        int ans = grid[i][j] + grid[lx][ly] + grid[rx][ry] + grid[dx][j];
                        sums.insert(ans);
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