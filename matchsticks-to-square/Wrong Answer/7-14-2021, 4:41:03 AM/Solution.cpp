// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        int sum = 0;
        accumulate(m.begin(),m.end(),sum);
        
        if(sum %4 !=0) return 0;
        
        sum /= 4;
        vector<int> dp(1 << n);
        
        for(int i = 0;i < 1 << n;i++){
            int su = 0;
            for(int j = 0;j < n;j++){
                if(i>>j&1) su += m[j];
                if(su == sum){
                    dp[i] = 1;
                }
            }
        }
        vector<int> masks;
        for(int i = 0;i < 1 << n;i++){
            if(dp[i] == 1){
                masks.push_back(i);
            }
        }        
        int M = masks.size();
        for(int i = 0;i < M;i++){
            cout << bitset<5>(i) << endl;
        }
        for(int a = 0;a < M;a++){
            for(int b = a+1;b < M;b++){
                if(a & b) continue;
                for(int c = b+1;c < M;c++){
                    if(a & b & c) continue;
                    for(int d = c+1;d < M;d++){
                        if(a & b & c & d) continue;
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};