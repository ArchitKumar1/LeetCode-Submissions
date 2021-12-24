// https://leetcode.com/problems/process-tasks-using-servers

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<tuple<int,int,int>> st;
        int n = servers.size();
        int m = tasks.size();
        int pos= 0;
        for(auto x : servers){
            st.emplace(0,x,pos++);
        }
        vector<int>res(m);
        
        map<int,vector<tuple<int,int,int>>> m1;
        queue<int> q;
        int j = 0;
        for(int i = 0; i <= (int)2e5;i++){
            if(i < m) q.push(i);
            // remove existing 
            for(auto x : m1[i]){
                auto it = st.find(x);
                int t,w,p;
                tie(t,w,p) = *it;
                //cout << i << " " << t << " " << w << " " << p << endl;
                st.erase(it);
                st.emplace(0,w,p);
            }
        
            while(q.size()){
                int j = q.front();
                int t,w,p;
                tie(t,w,p) = *st.begin();
                if(t <= tasks[j]){
                    st.erase(st.begin());
                    res[j] = p;
                    st.emplace(i+tasks[j],w,p);
                    m1[i+tasks[j]].push_back(make_tuple(i+tasks[j],w,p));
                    //cout << j << " " << i+tasks[j] <<  endl;
                    q.pop();
                }else{
                    break;
                }
            }
        }
        return res;
    }
};