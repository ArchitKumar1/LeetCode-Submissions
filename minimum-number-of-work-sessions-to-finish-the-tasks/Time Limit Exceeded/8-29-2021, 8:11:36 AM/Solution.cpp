// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        
        int n = tasks.size();
        
        vector<int> dp (1 << n,INT_MAX);
        dp[0] = 0;
        for(int i = 0;i < 1 << n;i++){
            for (int s=i; s; s=(s-1)&i){
                int time =0 ;
                for(int j = 0;j < n;j++){
                    if(s>>j&1) time += tasks[j];
                }
                if(time <= sessionTime){
                    dp[i] = min(dp[i],dp[i^s] + 1);
                }
            }
        }
        return dp[-1 + (1 << n)];
    }
};