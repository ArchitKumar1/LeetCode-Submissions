// https://leetcode.com/problems/decode-ways-ii

class Solution {
public:
    
    
    bool safe(string x){
        return x>="1" && x<="26";
    }
    int numDecodings(string s) {
        
        int n =s.size();
        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            if(s[i-1] == '*' ){
                dp[i] += 9*dp[i-1];
            }
            if(i-2>=0 && s.substr(i-2,2) == "**"){
                dp[i] += 26*dp[i-2];
            }
            if(safe(s.substr(i,1))){
                dp[i] += dp[i-1];
            }
            if(i-2>=0){
                if(safe(s.substr(i-1,2))){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
        
    }
};