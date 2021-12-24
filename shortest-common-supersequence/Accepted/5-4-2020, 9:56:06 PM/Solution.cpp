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
        int k = lcs.size();
        string ans = "";
        
        for(int K=0;K<k;K++){
            while(i<n && str1[i]!=lcs[K]){
                ans += str1[i];i++;
            }
            while(j<m && str2[j]!=lcs[K]){
                ans += str2[j];j++;
            }
            ans += lcs[K];      
            i++;j++;
        }
        cout << i << " " << j << endl;
        cout << ans << endl;
        if(i<n) ans += str1.substr(i);
        if(j<m) ans += str2.substr(j);
        return ans;
        
    }
};