// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string st) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = st.size();
        vector<vector<int>>p(n,vector<int>(26));
        vector<vector<int>>s(n,vector<int>(26));
        for(int i=0;i<n;i++){
            for(int j =0;j<26;j++){
                if((st[i]-'a') == j){
                    p[i][j] = 1;
                }
                if(i > 0){
                    p[i][j] |= p[i-1][j];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j =0;j<26;j++){
                if(st[i]-'a' == j){
                    s[i][j] = 1;
                }
                if(i<(n-1)){
                    s[i][j] |= s[i+1][j];
                }
            }
        }
        
        vector<vector<int>>cnt(26,vector<int>(26));
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            for(int j = 0;j < 26;j++){
                int l = p[i-1][j];
                int r = s[i+1][j];
                if(l > 0 && r > 0){
                    if(cnt[st[i]-'a'][j] == 0){
                        ans++;
                    }
                    cnt[st[i]-'a'][j]++;
                }
            }
        }
        return ans;
        
        
    }
};