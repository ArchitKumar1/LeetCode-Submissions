// https://leetcode.com/problems/course-schedule

class Solution {
public:
    
    vector<vector<int>> G;
    vector<int> col;
    bool safe  = 1 ;
    
    
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
    
    bool canFinish(int n, vector<vector<int>>& e) {
        G.resize(n);
        col.assign(n,0);
        for(auto x : e){
            auto u = x[0];
            auto v = x[1];
            G[v].push_back(u);
        }
        for(int i = 0;i<n;i++) if(col[i]!=2)dfs(i);
        for(int i = 0;i<n;i++){
            cout << col[i] << " ";
            if(col[i]!=2) return 0;
        }
        return 1;
        
    }
};