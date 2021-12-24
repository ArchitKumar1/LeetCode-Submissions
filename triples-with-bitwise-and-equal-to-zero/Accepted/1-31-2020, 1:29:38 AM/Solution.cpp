// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero

class Solution {
public:
    int countTriplets(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int dp[(1<<16)+1];
        fill(dp,dp+1+(1<<16),0);
        int n = A.size();
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                int o = (A[i]&A[j]);
                dp[o]+=1;
            }
        }
        int fans = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<(1<<16);j++){
                if((A[i]&j) == 0) fans +=dp[j];
            }
        }
        return fans;
        
    }
    
};