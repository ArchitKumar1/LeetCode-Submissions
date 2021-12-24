// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    bool check(string a,string b){
        int m = b.size();
        for(int i =0;i<m;i++){
            string t = b;
            t.erase(t.begin()+i);
            if(t == a){
                return 1;
            }
        }
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int dp[n+1] = {0};
        for(int i = 1;i<=n;i++){
            dp[i] = 1;
            for(int j = 1;j<i;j++){
                cout << words[i-1] << " " << words[j-1] << endl;
                if(check(words[j-1],words[i-1])){
                    
                    dp[i] = max(dp[i],dp[j] +1);
                }
            }
        }
        for(int i =1;i<=n;i++){
            cout << dp[i] << " ";
        }
        cout << endl;
        return dp[n];
        
    }
};