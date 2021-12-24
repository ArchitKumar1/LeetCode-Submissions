// https://leetcode.com/problems/keys-and-rooms

class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms,int roomno,int visited[]){
        visited[roomno] = 1;
        for(int i=0;i<rooms[roomno].size();i++){
            if(visited[rooms[roomno][i]]==0)
                dfs(rooms,rooms[roomno][i],visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int visited[rooms.size()];
        memset(visited,0,sizeof(visited));
        dfs(rooms,0,visited);
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==0)
                return false;
        }
        return true;
    }
};