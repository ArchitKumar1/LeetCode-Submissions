// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    int n,m;
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> ans;
        if(ma.size() == 0) return ans;
        n = ma.size();
        m = ma[0].size();
        
        
        int x = 0,y= 0;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int pos = 0;
        while(1){
            cout << x << " " << y << " " << pos <<  endl;
            ans.push_back(ma[x][y]);
            ma[x][y] = 0;
            int X = dir[pos][0] + x;
            int Y = dir[pos][1] + y;
            
            cout << X << " " << Y << endl;
            if (X < 0 || Y < 0 || X > n-1 || Y > m-1 ||ma[X][Y] == 0){
                pos = (pos+1)%4;
                X = dir[pos][0] + x;
                Y = dir[pos][1] + y;
                if(X < 0 || Y < 0 || X > n-1 || Y > m-1||ma[X][Y] == 0 ){
                    break;
                }
            }
            x = X;
            y = Y;
        }
        return ans;
        
    }
};