// https://leetcode.com/problems/can-i-win

class Solution {
public:
    vector<int> dp;
    int maxnum;
    int MCI;
    bool solve(int mask,int sum,int cnt = 0){
        if(dp[mask]!=-1) return dp[mask];
        cout << cnt << endl;
        for(int i = 1;i<=MCI;i++){
            if(!(mask&(1 << (i-1)))){
                bool ans = (i>= sum || solve(mask|(1<<(i-1)),sum-i,cnt+1));
                ans &= (cnt%2 == 0);
                if(ans){
                    return dp[mask] = 1;
                }
            }
        }
        return dp[mask] = 0;
        
    }
    bool canIWin(int mci, int sum) {
        dp.assign(1<<21,-1);
        MCI = mci;
        return solve(0,sum);
    }
};