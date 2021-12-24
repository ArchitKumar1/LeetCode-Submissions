// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<vector<int>> G;
     vector<vector<int>> iG;
    vector<int> col;
    bool safe  = 1 ;
    
    vector<int> temp;
    
    
    void dfs(int s){
        
        col[s] = 1;
        for(int c  : G[s]){
            if(col[c] == 1){
                safe = 0;
                return;
            } else if(col[c] == 0){
                dfs(c);
            }
        }
        col[s] = 2;
    }
    
    void dfs2(int s){
        temp.push_back(s);
        for(int c  : G[s]){
            dfs2(c);
        }
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        G.resize(n);
        iG.resize(n);
        col.assign(n,0);
        for(auto x : e){
            auto u = x[0];
            auto v = x[1];
            G[v].push_back(u);
            iG[u].push_back(v);
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(col[i]!=2)dfs(i);
        } 
        if(safe){
            for(int i = 0;i<n;i++){
                if(iG[i].size() == 0){
                     cout << i << endl;
                    dfs2(i);
                    for(int c : temp){
                        ans.push_back(c);
                        temp.clear();
                    }
                } 
            } 
        }
        
        return ans;
        
    }
};