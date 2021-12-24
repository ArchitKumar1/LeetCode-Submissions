// https://leetcode.com/problems/walking-robot-simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0, y = 0;
        int dist = 0;
        set<pair<int, int>> obstacleSet;
        int pos = 0;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        for(int i=0;i<commands.size();i++){
            if(commands[i] == -1){
                pos = (pos + 1) % 4;
            }
            else if(commands[i] == -2){
               pos = (pos + 3) % 4;
            }
            else{
                int t = commands[i];
                for(int j=0;j<t;j++){
                    pair<int,int> temp = {x + dir[pos][0],y+dir[pos][1]};
                    if (obstacleSet.find(temp) == obstacleSet.end()){
                        x+=dir[pos][0];
                        y+=dir[pos][1];
                        dist = max(dist,x*x +y*y);
                    }
                }   
            }
        }
        return dist;
        
    }
};