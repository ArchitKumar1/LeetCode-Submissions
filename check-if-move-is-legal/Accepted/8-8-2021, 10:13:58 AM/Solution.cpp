// https://leetcode.com/problems/check-if-move-is-legal

class Solution {
public:
    bool checkMove(vector<vector<char>>& b, int i, int j, char c) {
        int dx[8] = {0,1,1,1,0,-1,-1,-1};
        int dy[8] = {1,1,0,-1,-1,-1,0,1};
        int n = b.size(),m = b[0].size();
        bool ans = 0;
        for(int k = 0;k < 8;k++){
            if(b[i][j] != '.') continue;
            char base = c;
            int x = i,y = j;
            int cnt = 0;
            while(true){
                x += dx[k];
                y += dy[k];
                if(!( x>=0 && x<n && y>=0 && y < m)) break;
                if(b[x][y] == '.'){
                    break;
                }else if(b[x][y] == base){
                    if(cnt) ans = 1;
                    break;
                }else{
                    cnt++;
                }
            }
        }
        return ans;
    }
};