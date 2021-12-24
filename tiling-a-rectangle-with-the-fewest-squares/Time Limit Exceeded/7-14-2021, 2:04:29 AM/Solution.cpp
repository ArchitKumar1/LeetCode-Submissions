// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares

class Solution {
public:
    
    int tilingRectangle(int n, int m) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        
        int S = min(n,m);
        auto present = [&](int x,int y,int sz,int val) -> bool{
            for(int i = x;i < x+sz ;i++){
                for(int j = y;j <y+sz ;j++){
                    if(grid[i][j] != val) return 0;
                }
            }
            return 1;
        };
        auto done = [&]() -> bool{
            for(int i = 0;i < n;i++){
                for(int j = 0;j < m;j++){
                    if(grid[i][j] == 0) return 0;
                }
            }
            return 1;
        };
        auto paint = [&](int x,int y,int sz,int val) -> void{
            //assumes it can paint
            for(int i = x;i < x+sz;i++){
                for(int j = y;j < y+sz ;j++){
                    grid[i][j] = val;
                }
            }
        };
        
        auto unused = [&](){
            //assumes it can paint
            vector<pair<int,int>> points;
            for(int i = 0;i < n;i++){
                for(int j =0;j < m;j++){
                    if(grid[i][j] == 0) points.emplace_back(i,j);
                }
            }
            return points;
        };
        auto print = [&](){
            //assumes it can paint
            for(int i = 0;i < n;i++){
                for(int j =0;j < m;j++){
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
        };
        int fans = INT_MAX;
        function<void(int)> dfs = [&](int cnt){
            //print();
            //cout << cnt << endl;
            // check if the grid is competely full;
            if(done()){
                //cout << "mila" << endl;
                fans = min(fans,cnt);
                return;
            }
            vector<pair<int,int>> points = unused();
            for(auto [x,y] : points){
                //cout << x << " " << y << endl;;
                for(int s = 1;s <= S;s++){
                    if(x + s <= n && y + s <= m){
                        if(present(x,y,s,0)){
                            //cout << x << " " << y << " " << s << endl;
                            paint(x,y,s,1);
                            dfs(cnt+1);
                            paint(x,y,s,0);
                        }
                    }
                }
            }
        };
        dfs(0);
        return fans;
    }
};