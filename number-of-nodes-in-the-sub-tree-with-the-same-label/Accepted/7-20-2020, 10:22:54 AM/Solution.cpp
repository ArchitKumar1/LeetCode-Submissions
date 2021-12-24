// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public:
    
    void dfs(int s, int par,vector<int> &cnt,string &labels,vector<vector<int>>&G,vector<int> &ans){
        int x = cnt[labels[s]-'a'];
        cnt[labels[s]-'a']++;

        for(int c : G[s]){
            if(c == par ) continue;
            dfs(c,s,cnt,labels,G,ans);
        }
        ans[s] = cnt[labels[s]-'a'] - x;
        
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        
        vector<vector<int>>G(n);
        for(auto v :e){
            auto x = v[0];
            auto y = v[1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        vector<int>cnt(26,0);

        vector<int> ans(n);
        dfs(0,-1,cnt,labels,G,ans);
        return ans;
    }
};