// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        ios_base:: sync_with_stdio(false);
        cin.tie(NULL);
        int n = A.size();
        int dp[n+1][26];
        vector<string> ans;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<A[i].length();j++){
                    dp[i][A[i][j] - 'a']++;
                }
            
        }
        for(int i=0;i<26;i++){
            int z = (int) 1e9;
            for(int j = 0;j<n;j++){
                z = min(z,dp[j][i]);    
            }
            char p = 'a' + i;
            string s = "";
            s += p;
            while(z--){
                ans.push_back(s);
            }
        }
        return ans;
    }
};