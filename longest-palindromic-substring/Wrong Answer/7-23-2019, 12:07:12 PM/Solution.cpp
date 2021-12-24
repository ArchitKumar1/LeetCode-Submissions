// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        if(n == 0) return "";
        if(n == 1) return s;
        int dp[n][n];
        int index= 0;
        int val = INT_MIN;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;            
            index= i;
            val =0;
            
        }
        for(int i=0;i<n -1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;                
                index= i;
                val = 1;      
                cout << val << index << endl;
            }
        }
        
        for(int k = 2;k<n;k++){
            for(int i = 0;i + k < n;i++){
                if(s[i] == s[i+k] && dp[i+1][i+k-1] == 1){
                    dp[i][i+k] =1 ;
                    cout << "OK" << endl;
                    if(i+k - i + 1>val){
                        index= i;
                        val = k+1;
                    }
                }
            }
        }
         cout << val << index << endl;
        return s.substr(index,index + val+1);
    }
};