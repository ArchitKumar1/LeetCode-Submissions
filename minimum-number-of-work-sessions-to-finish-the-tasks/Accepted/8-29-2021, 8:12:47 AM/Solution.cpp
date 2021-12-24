// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        
        int n = tasks.size();
        
        vector<int> dp (1 << n,INT_MAX);
        dp[0] = 0;
        
        vector<int> sums(1 << n,0);
        
         for(int i = 0;i < 1 << n;i++){
            for(int j = 0;j < n;j++){
                if(i>>j&1) sums[i] += tasks[j];
            }
         }
        for(int i = 0;i < 1 << n;i++){
            for (int s=i; s; s=(s-1)&i){
                
                if(sums[s] <= sessionTime){
                    dp[i] = min(dp[i],dp[i^s] + 1);
                }
            }
        }
        return dp[-1 + (1 << n)];
    }
};