// https://leetcode.com/problems/process-tasks-using-servers


class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<tuple<int,int,int>> used;
        int n = servers.size();
        int m = tasks.size();
        int pos= 0;
        set<tuple<int,int>> free;
        for(auto x : servers){
            free.emplace(x,pos++);
        }
        vector<int>res(m);
        
        queue<int> q;
        int j = 0;

        for(int i = 0; i < m;i++){
            while(used.size()){
                int t,w,p; tie(t,w,p) = *used.begin(); 
                if(t > i) break;
                used.erase(used.begin());
                free.emplace(w,p);
            }
            if(free.size()==0){
                int t,w,p; tie(t,w,p) = *used.begin(); 
                res[i] = p;
                used.erase(used.begin());
                used.emplace(i+tasks[i],w,p);
            }
            else{
                int w,p; tie(w,p) = *free.begin();
                res[i] = p;
                free.erase(free.begin());
                used.emplace(i+tasks[i],w,p);
            }
        }
        return res;
    }
};