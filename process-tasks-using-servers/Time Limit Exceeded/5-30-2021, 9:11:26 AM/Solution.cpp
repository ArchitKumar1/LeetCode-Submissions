// https://leetcode.com/problems/process-tasks-using-servers

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<tuple<int,int>> st;
        int n = servers.size();
        int m = tasks.size();
        int pos= 0;
        map<int,vector<tuple<int,int>>> ms;
        for(auto x : servers){
            ms[0].emplace_back(x,pos++);
        }
        vector<int>res(m);
        
        queue<int> q;
        int j = 0;
        
        for(int i = 0; i <= (int)2e5;i++){
            if(i < m) q.push(i);
            for(auto x : ms[i]){
                int w,p;
                tie(w,p) = x;
                //cout << i << " " << t << " " << w << " " << p << endl;
                st.emplace(w,p);
            }
        
            while(q.size() && st.size()){
                int j = q.front();
                int w,p;
                tie(w,p) = *st.begin();
                
                st.erase(st.begin());
                res[j] = p;
                ms[i+tasks[j]].push_back(make_tuple(w,p));
                //cout << j << " " << i+tasks[j] <<  endl;
                q.pop();
            }
        }
        return res;
    }
};