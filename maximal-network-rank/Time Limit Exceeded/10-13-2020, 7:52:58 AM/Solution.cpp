// https://leetcode.com/problems/maximal-network-rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>G(n);
        for(auto r : roads){
            int u = r[0],v=r[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int fans = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                set<pair<int,int>> s1;
                for(int c : G[i]){
                    pair<int,int> p = {c,i};
                    if(p.first < p.second) swap(p.first,p.second);
                    s1.insert(p);
                }
                for(int c : G[j]){
                    pair<int,int> p = {c,j};
                    if(p.first < p.second) swap(p.first,p.second);
                    s1.insert(p);
                }
                fans = max(fans,(int)s1.size());
            }
            
        }
        return fans;
    }
};