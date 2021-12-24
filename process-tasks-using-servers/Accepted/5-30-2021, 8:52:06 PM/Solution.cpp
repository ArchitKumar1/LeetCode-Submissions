// https://leetcode.com/problems/process-tasks-using-servers


class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> used;
        int n = servers.size();
        int m = tasks.size();
        int pos= 0;
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> free;
        for(auto x : servers){
            free.emplace(x,pos++);
        }
        vector<int>res(m);
        
        queue<int> q;
        int j = 0;

        for(int i = 0; i < m;i++){
            while(used.size() && get<0>(used.top()) <= i){
                int t,w,p; tie(t,w,p) = used.top();used.pop();
                free.push({w,p});
            }
            if(free.size()==0){
                int t,w,p; tie(t,w,p) = used.top();used.pop();
                res[i] = p;
                used.push({t+tasks[i],w,p});
            }
            else{
                int w,p; tie(w,p) = free.top();free.pop();
                res[i] = p;
                used.push({i+tasks[i],w,p});
            }
        }
        return res;
    }
};