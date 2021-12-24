// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    vector<vector<int>> adj; 
    vector<bool> visited;
    vector<int> tin, low;
    vector<vector<int>> ans;
    int timer= 0 ;
    void dfs(int s ,int par){
        visited[s] =true;
        tin[s] = low[s] = timer++;
        for(int c : adj[s]){
            if(c == par) continue;
            if(visited[c]){
                low[s] = min(low[s],tin[c]);
            }else{
                dfs(c,s);
                low[s] = min(low[s],low[c]);
                if(low[c] > tin[s]){
                    ans.push_back(vector<int>({c,s}));
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        adj.resize(n+1);
        visited.assign(n,0);
        tin.assign(n,0);
        low.assign(n,0);
        
        for(vector<int> v : c){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i = 0;i<n;i++){
            if(visited[i] == 0){
                dfs(i,-1);
            }
        }
        return ans;
    }
};