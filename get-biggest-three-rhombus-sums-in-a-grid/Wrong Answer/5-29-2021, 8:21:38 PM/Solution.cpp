// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> sums;
        int n= grid.size(),m = grid[0].size();
        auto check = [&](int x ,int y) -> bool{
            return x>=0 && y >=0 && x < n && y < m;
        };
        for(int i = 0;i <n;i++){
            for(int j = 0;j <m;j++){
                sums.push_back(grid[i][j]);
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
                        sums.push_back(ans);
                    }
                }
            }
        }
        sort(sums.rbegin(),sums.rend());
        sums.resize(3);
        return sums;
    }
};