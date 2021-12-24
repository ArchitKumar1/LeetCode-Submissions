// https://leetcode.com/problems/count-nodes-with-the-highest-score

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> G(n);
        for(int i = 0; i < n;i++){
            if(parents[i] == -1) continue;
            G[parents[i]].push_back(i);
        }
        vector<int> sz(n);
        
        function<void(int,int)> dfs = [&](int s,int par) -> void{
            sz[s] += 1;
            for(int c : G[s]){
                if(c == par)continue;
                dfs(c,s);
                sz[s] += sz[c];
            }
        };
        dfs(0,0);
        vector<int64_t> scores;
        function<void(int,int)> dfs2 = [&](int s,int par) -> void{
            // in out dp
            int64_t prod = 1;
            
            int subtreesum = 1;
            
            for(int c : G[s]){
                if(c == par)continue;
                dfs2(c,s);
                subtreesum += sz[c];
                prod *= sz[c];
            }
            int outsum = n - subtreesum;
            if(outsum == 0) outsum = 1;
            prod = prod * outsum;
            scores.push_back(prod);
        };
        dfs2(0,0);
        // for(int s : scores){
        //     cout << s << " ";
        // }
        // cout << endl;
        int maxi = *max_element(scores.begin(),scores.end());
        int counts = count(scores.begin(),scores.end(),maxi);
        return counts;
    }
};