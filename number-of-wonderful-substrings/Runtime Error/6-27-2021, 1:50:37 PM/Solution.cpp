// https://leetcode.com/problems/number-of-wonderful-substrings

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        
        const int N = 1 << 10;
        vector<int> dp(N,0);
        dp[0] = 1;
        
        int mask = 0;
        int ans = 0;
        for(char c : word){
            mask ^= (1 << (c-'a'));
            
            ans += dp[mask];
            for(int  i =0;i < 10;i++){
                ans += dp[mask^(1 << i)];
            }
            dp[mask]++;
        }
        return ans;
    }
};