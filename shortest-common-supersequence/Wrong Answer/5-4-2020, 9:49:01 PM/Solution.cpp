// https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        vector<char> pos;
        int i = n;
        int j = m;
        
        while(i>=1 && j>=1){
            if(str1[i-1] == str2[j-1]){
                pos.push_back(str1[i-1]);
                i--;j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]) {
                    i--;
                }else{
                    j--;
                }
            }
        }
            
        
        reverse(pos.begin(),pos.end());
        string lcs = "";
        for(char p : pos){
            lcs += p;
        }
        cout << lcs << endl;
        i = 0;
        j = 0;
        int k = 0;
        string ans = "";
        while(i<n && j<m){
            while(str2[j]!=lcs[k]){
                ans += str2[j];j++;
            }
            while(str1[i]!=lcs[k]){
                ans += str1[i];i++;
            }
            
            
            ans += lcs[k];
            i++;j++;k++;            
        }
        cout << ans << endl;
        if(i<n) ans += str1.substr(i);
        if(j<m) ans += str2.substr(j);
        return ans;
        
    }
};