// https://leetcode.com/problems/detonate-the-maximum-bombs

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> G(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                long long int dist = 1LL*(bombs[i][0]-bombs[j][0]) * (bombs[i][0]-bombs[j][0]) +
                     1LL*(bombs[i][1]-bombs[j][1]) * (bombs[i][1]-bombs[j][1]);
                if(dist <= 1LL* bombs[i][2] * bombs[i][2]) G[i].push_back(j);
            }
        }
        vector<int> vis(n);
        function<int(int)> dfs = [&](int s){
            vis[s] = 1;
            int cnt = 1;
            for(int c : G[s]){
                if(!vis[c]){
                    cnt += dfs(c);
                }
            }
            return cnt;
        };
        int val=0,ans=0;
        for(int i = 0;i < n;i++){
            vis.assign(n,0);
            ans = max(ans,dfs(i));
        }
        return ans;
    }
};