// https://leetcode.com/problems/smallest-sufficient-team

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string,int> m1;
        int pos = 0;
        for(string s : req_skills) m1[s] = pos++;
        
        int n = people.size();
        int m = req_skills.size();
        
        vector<long long> peop(n);
        for(int i =0;i<n;i++){
            for(auto s :people[i] ){
                peop[i] |= 1LL << (m1[s]);
            }
        }
        vector<long long> dp(1 << m,1e18);
        vector<long long> sol(1 << m,0);
        dp[0] = 0;
        for(int p = 0;p<n;p++){
            vector<long long> ndp = dp;
            for(int i = 0;i < 1LL << m ;i++){
                int next = i | peop[p];
                if(ndp[next] >  1 + dp[i] ){
                    ndp[next] = 1 + dp[i];
                    sol[next] = sol[i] | (1LL << p);
                }
            }
            swap(ndp,dp);
        }
        vector<int> ans;
        long long val = sol.back();
        for(int i = 0; i < n; i++ ){
            if (val>>i&1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};