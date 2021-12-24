// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
    
        
        int fans = 0;
        for(int i =0;i<n;i++){
            vector<int> arr(m,0);
            for(int i2 = i;i2<n;i2++){
                for(int j = 0;j<m;j++){
                    arr[j] += matrix[i2][j];
                }
                unordered_map<int,int> m1;
                m1[0] = 1;
                int rsum = 0;
                for(int c : arr){
                    rsum += c;
                    fans += m1[rsum-target];
                    m1[rsum]++;
                }
            }
        }
        return fans;
        
    }
};