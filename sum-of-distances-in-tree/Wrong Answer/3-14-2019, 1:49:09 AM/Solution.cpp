// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    int M = 11000;
    int nodes;
    
    
    void dfs(int s,int par,vector<vector<int>>& G,vector<int> &ans,vector<int> &children){
        int x = 0,y = 0;
        for(auto c : G[s]){
            if(c == par) continue;
            dfs(c,s,G,ans,children);
            children[s] += children[c];
            ans[s] +=  children[c] + ans[c];
        }
        children[s] += 1 ; 
        
    }
    void dfs2(int s,int par,vector<vector<int>>& G,vector<int> &ans,vector<int> &children){
        
        for(auto c : G[s]){
            if(c == par) continue;
            ans[c] = ans[s] - children[c] + nodes - children[c];
            dfs2(c,s,G,ans,children);
        }
        
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        nodes = N;
        vector<vector<int> >  G = vector<vector<int> >  (N);
        vector<int> ans = vector<int>(N);
        vector<int> children = vector<int>(N);
        for(auto c: edges){
            G[c[0]].push_back(c[1]);
        }
        dfs(0,-1,G,ans,children);
        dfs2(0,-1,G,ans,children);
        vector<int> x;
        for(int i=0;i<N;i++){
            x.push_back(ans[i]);
        }
        return x;
        
    }
};