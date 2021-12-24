// https://leetcode.com/problems/path-crossing

class Solution {
public:
    bool isPathCrossing(string s) {
        bool safe = 0;
        pair<int,int> p= {0,0};
        map<pair<int,int>,int> m1;
        m1[p] = 1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        string dir = "NSEW";
        for(char c : s ){
            for(int i =0;i<4;i++){
                if(c == dir[i]){
                    p.first += dx[i];
                    p.second += dy[i];
                }
            }
            if(m1[p] == 1){
                safe = 1;
                break;
            }
            m1[p] = 1;
            
            
        }
        return safe;
    }
    
};