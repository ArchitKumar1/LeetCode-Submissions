// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    vector<vector<int>> G;
    vector<int> temp;
    vector<int> vis;
    // int find(int v){
    //     return (par[v] == v ? v : par[v] = find(par[v]));
    // }
    // void merge(int a,int b){
    //     a = find(a);
    //     b = find(b);
    //     if(a == b) return;
    //     par[a] = b;
    // }
    void dfs(int s){
        vis[s] = 1;
        temp.push_back(s);
        for(int c : G[s]){
            if(vis[c] == 0){
                dfs(c);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        G.resize(n+1);
        vis.assign(n,0);
        for(auto v : c){
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        vector<vector<int>> cc;
        for(int  i= 0;i<n;i++){
            if(vis[i] == 1) continue;
            temp.clear();
            dfs(i);
            cc.push_back(temp);
        }
        int extra = 0;
        int needed = cc.size() - 1;
        
        for(auto v : cc){
            int edges = 0;
            for(int s : v){
                edges += G[s].size();
            }
            edges/=2;
            extra += (edges - v.size() + 1);
        }
        cout << extra << " " << needed << endl;
        if(extra >= needed){
            return needed;
        }else{
            return -1;
        }
        
        
    }
};