// https://leetcode.com/problems/decode-ways-ii

class Solution {
public:
    
    map<string,int> m1;
    
    int cnt(string s) {
        // 11-26, except 20 because '*' is 1-9
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0'? 0:1;
        }else if (s == "**")  {
            return 15;
        }
        else if (s[1] =='*') {
            if (s[0] =='1') return 9;
            return s[0] == '2'? 6:0;
        }
        else if (s[0] == '*') {
            return s[1] <= '6'? 2:1;
        }
        else {
            // if two digits, it has to be in [10 26]; no leading 0
            return stoi(s) >= 10 && stoi(s) <= 26? 1:0; 
        }
        return 0;
    }
    int numDecodings(string s) {
        
        const int MOD = 1e9+7;
        int n =s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            dp[i] += dp[i-1]*cnt(s.substr(i-1,1));
            if(i-2>=0)
                dp[i] += dp[i-2]*cnt(s.substr(i-2,2));
            dp[i] %= mod;
        }
        return dp[n];
        
    }
};