// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public:
    
    void dfs(int s, int par,vector<vector<int>> &cnt,string &labels,vector<vector<int>>&G){
        cnt[s][labels[s]-'a']++;

        for(int c : G[s]){
            if(c == par ) continue;
            dfs(c,s,cnt,labels,G);
            for(int i = 0;i<26;i++){
                cnt[s][i] += cnt[c][i];
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        
        vector<vector<int>>G(n);
        for(auto v :e){
            auto x = v[0];
            auto y = v[1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        vector<vector<int>>cnt(n,vector<int>(26,0));

         
        dfs(0,-1,cnt,labels,G);
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            ans[i] = cnt[i][labels[i]-'a'];
        }
        return ans;
    }
};