// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    int M = 11000;
    int nodes;
    vector<vector<int> >  G = vector<vector<int> >  (M);
    vector<int> ans = vector<int>(M);
    vector<int> children = vector<int>(M);
    
    void dfs(int s,int par = -1){
        int x = 0,y = 0;
        for(auto c : G[s]){
            if(c == par) continue;
            dfs(c,s);
            children[s] += children[c];
            ans[s] +=  children[c] + ans[c];
        }
        children[s] += 1 ; 
        
    }
    void dfs2(int s,int par){
        
        for(auto c : G[s]){
            if(c == par) continue;
            ans[c] = ans[s] - children[c] + nodes - children[c];
            dfs2(c,s);
        }
        
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
         nodes = N;
        for(auto c: edges){
            G[c[0]].push_back(c[1]);
        }
        dfs(0,-1);
        dfs2(0,-1);
        vector<int> x;
        for(int i=0;i<N;i++){
            x.push_back(ans[i]);
        }
        return x;
        
    }
};