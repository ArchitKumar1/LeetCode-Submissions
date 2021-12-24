// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        string S = "RDLU";
        int x = 0;
        int y = 0;
        for(char c : moves){
            int pos = 0;
            for(char d : S){
                if(c == d){
                    x += dx[pos];
                    y += dy[pos];
                }
                pos++;
            }
        }
        return x == 0 && y == 0;
        
    }
};