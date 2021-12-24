// https://leetcode.com/problems/largest-magic-square

class Solution {
public:
    
 
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fans = 0;
        vector<vector<int>> rs = grid;
        vector<vector<int>> cs = grid;
        
        for(int i = 0;i < n;i++){
            for(int j=1;j< m;j++){
                rs[i][j] += rs[i][j-1];
            }
        }
        for(int j=0;j< m;j++){
            for(int i = 1;i < n;i++){
                cs[i][j] += cs[i-1][j];
            }
        }
        auto gr = [&](int r,int c1,int c2){
            if( c1 == 0 ) return rs[r][c2];
            else return rs[r][c2] - rs[r][c1-1];
        };
        auto gc = [&](int c,int r1,int r2){
            if( r1 == 0 ) return cs[r2][c];
            else return cs[r2][c] - cs[r1-1][c];
        };
        for(int i = 0;i < n;i++){
            for(int j=0;j< m;j++){
                for(int k=1;k+i -1 < n && k+j-1 < m;k++){
                    int len = k;
                    int d1=0,d2=0;
                    bool ans = true;
                    for(int x = 0;x<len;x++){
                        // cout << i + x << " " << j + x << endl;
                        d1 += grid[i+x][j+x];
                        d2 += grid[i+x][len-1+j-x];
                    }
                    if(d1 != d2) ans = false;
                    int rows = 0;
                    for(int x = 0;x<len;x++){
                        
                        rows = gr(i+x,j,j+len-1);
                        // if(i==1&&j==1){
                        //     cout << rows  << endl;
                        // }
                        if(rows!=d1) ans = false;
                    }
                    int cols = 0;
                    for(int x = 0;x<len;x++){
                        cols = gc(j+x,i,i+len-1);
                        // if(i==1&&j==1){
                        //     cout << cols  << endl;
                        // }
                        if(cols!=d1) ans = false;
                    }
                    if(ans == true) fans = max(fans,len);
                    // if(i==1&&j==1){
                    //     cout << d1 << " " << d2 << " " << ans << endl;
                    // }
                }
            }
        }
        cout << endl;
        return fans;
    }
};