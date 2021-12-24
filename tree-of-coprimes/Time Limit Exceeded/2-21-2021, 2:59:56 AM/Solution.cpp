// https://leetcode.com/problems/tree-of-coprimes

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n = nums.size();
        vector<vector<int>> G(n);
        
        for(auto e : edges){
            int u = e[0],v=e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
    
        vector<stack<pair<int,int>>> facts(51);
        vector<int> fans(n,-1);
        
        function<void(int,int,int)> dfs = [&](int s,int par,int d) -> void {
            int best = -1;
            int ans = -1;
            for(int i = 1;i<=50;i++){
                if(__gcd(nums[s],i) == 1){
                    if(facts[i].size() && facts[i].top().second > best){
                        cout << s << " " << i << " " << facts[i].top().first << " "<< facts[i].top().second << endl;
                        best = facts[i].top().second;
                        ans = facts[i].top().first;
                    }
                }
            }
            fans[s] = ans;
            facts[nums[s]].push({s,d});
            for(int c : G[s]){
                if(c != par) dfs(c,s,d+1);
            }
            facts[nums[s]].pop();
        };
        
        
        dfs(0,0,0);
        return fans;
    }
};