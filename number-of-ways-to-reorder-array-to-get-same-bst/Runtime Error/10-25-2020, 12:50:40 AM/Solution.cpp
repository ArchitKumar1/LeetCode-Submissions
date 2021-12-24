// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst

class Solution {
    
    const static int N = 1200;
    const int mod = 1e9+7;
public:
    
    int ncr[N][N];
    
    int dfs(vector<int>nums){
        int n = nums.size();
        if(n == 1 || n == 0) return 1;
        
        vector<int> l,r;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[0]) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }
        
        return dfs(l)* dfs(r) %mod *ncr[n-1][l.size()]%mod;
    }
    int numOfWays(vector<int>& nums) {
        memset(ncr,0,sizeof(ncr));
        
        
        for(int i = 1;i<N;i++){
            ncr[i][0] = 1;
            ncr[i][i] = 1;
            for(int j = 1;j<i;j++){
                ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
                ncr[i][j] %= mod;
            }
        }
        return dfs(nums)-1;
        
    }
};