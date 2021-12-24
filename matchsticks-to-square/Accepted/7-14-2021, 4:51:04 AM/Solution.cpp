// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        int sum = 0;
        for(int c : m) sum+= c;
        
        if(sum %4 !=0) return 0;
        
        sum /= 4;
        vector<int> dp(1 << n);
        
        for(int i = 0;i < 1 << n;i++){
            int su = 0;
            for(int j = 0;j < n;j++){
                if(i>>j&1) su += m[j];
            }
            if(su == sum){
                dp[i] = 1;
            }
        }
        vector<int> masks;
        for(int i = 0;i < 1 << n;i++){
            if(dp[i] == 1){
                masks.push_back(i);
            }
        }        
        int M = masks.size();
        for(int a = 0;a < M;a++){
            for(int b = a+1;b < M;b++){
                if(masks[a] & masks[b]) continue;
                for(int c = b+1;c < M;c++){
                    if((masks[a] & masks[b]) || (masks[b] & masks[c]) || (masks[c] & masks[a])) continue;
                    for(int d = c+1;d < M;d++){
                        if( (masks[a] ^ masks[b] ^ masks[c] ^ masks[d]) != (-1 + (1 << n)) ) continue;
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};