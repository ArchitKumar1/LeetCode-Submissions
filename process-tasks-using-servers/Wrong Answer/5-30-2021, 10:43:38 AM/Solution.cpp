// https://leetcode.com/problems/process-tasks-using-servers


class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<tuple<int,int>> st;
        int n = servers.size();
        int m = tasks.size();
        int pos= 0;
        set<tuple<int,int,int>> ms;
        for(auto x : servers){
            ms.emplace(0,x,pos++);
        }
        vector<int>res(m);
        
        queue<int> q;
        
        for(int i = 0,T = 0; i < m;i++){
            T = max(i,T);
            q.push(i);
            while(ms.size()){
                int t,w,p;
                auto it = ms.begin();
                tie(t,w,p) = *it;
                if(t <= T){
                    ms.erase(it);
                    st.emplace(w,p);
                }else{
                    break;
                }
            }
        
            while(q.size() && st.size()){
                int j = q.front();
                int w,p;
                tie(w,p) = *st.begin();
                
                st.erase(st.begin());
                res[j] = p;
                ms.emplace(make_tuple(i+tasks[j],w,p));
                q.pop();
            }
        }
        return res;
    }
};