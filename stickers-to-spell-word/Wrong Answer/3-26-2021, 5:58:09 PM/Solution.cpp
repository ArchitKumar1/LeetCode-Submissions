// https://leetcode.com/problems/stickers-to-spell-word

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {

        int n = target.size();
        int m = 1 << n;
        vector<int> dp(m,1e9);
        
        dp[0] = 0;
        for(int i = 0;i < m;i++){
            for(string s : stickers){
                int ni = i;
                for(char c : s){
                    for(int j = 0;j<n;j++){
                        if((ni>>j&1) == 0 && target[j] == c){
                            ni |= (1 << j);
                            break;
                        }
                    }
                }
                dp[ni] = min(dp[ni],dp[i]+1);
            }
        }
        return dp[m-1];
    }

};