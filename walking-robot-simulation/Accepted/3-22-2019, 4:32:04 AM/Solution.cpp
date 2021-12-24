// https://leetcode.com/problems/walking-robot-simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0, y = 0;
        int dist = 0;
        map<pair<int,int>,int> m1;
        int pos = 0;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto c : obstacles){
            m1[{c[0],c[1]}]++;
        }
        for(int i=0;i<commands.size();i++){
            if(commands[i] == -1){
                pos = (pos + 1) % 4;
            }
            else if(commands[i] == -2){
               pos = (pos + 3) % 4;
            }
            else{
                int t = commands[i];
                int s = 0;
                for(int j=0;j<t;j++){
                    pair<int,int> temp = {x + dir[pos][0],y+dir[pos][1]};
                    if(m1[temp] == 0){
                        x+=dir[pos][0];
                        y+=dir[pos][1];
                        dist = max(dist,(int)pow(x,2)+(int)pow(y,2));
                    }
                }   
            }
        }
        return dist;
    }
};