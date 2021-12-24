// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs

class Solution {
public:
    int K;
    int N;
    vector<int> J;
    
    int solve(int worker,int free ){
        
        if(worker == K){
            if(free == 0){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        if(free == 0){
            return 1e9;
        }
        int fans = 1e9;
        
        for(int s=free ;s; s=(s-1)&free){
            if(s > 0){
                int ans = 0;
                for(int i = 0;i<N;i++){
                    if(s>>i&1)
                        ans += J[i];
                }
                fans = min(fans,max(ans, solve(worker+1,free^s)));
            }
            
        }
        return fans;
        
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        J = jobs,N = J.size(),K = k;
        return solve(0,(1<<N)-1);
    }
};