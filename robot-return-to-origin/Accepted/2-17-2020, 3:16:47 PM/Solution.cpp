// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        string ss = "RDLU";
        for(char c : moves){
            for(int i = 0;i<4;i++){
                if(ss[i] == c){
                    x += dx[i];
                    y += dy[i];
                }
            }
        }
        return (x == 0 && y==0);
    }
};