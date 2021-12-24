// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {  
        if(e.size() == 0) return 0;
        auto cmp = [](vector<int> &a,vector<int> &b){
            return ((long)a[1]*a[0] < (long)b[0]*b[1]); 
        };
        int n = e.size();
        
        sort(e.begin(),e.end(),cmp);
        
        for(auto x : e){
            for(auto y : x){
                cout << y << " ";
            }
            cout << endl;
        }
        vector<int> dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(e[i][0] > e[j][0] && e[i][1] > e[j][1]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }
        return dp[n-1];
    }
};