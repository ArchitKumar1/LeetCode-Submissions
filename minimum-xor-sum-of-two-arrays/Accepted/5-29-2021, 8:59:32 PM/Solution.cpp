// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         int m = nums2.size();
        
        vector<int> dp(1 << m,1e9);
        dp[0] = 0;
        for(int i = 0;i <n;i++){
            vector<int> ndp(1 << m,1e9);
            for(int ma = 0; ma < 1 << m;ma++){
                for(int j = 0;j < m;j++){
                    if((ma>>j&1) ==0 ){
                        int nma = ma | (1 << j);
                        ndp[nma] = min(ndp[nma], dp[ma] + (nums1[i]^nums2[j]));
                    }
                }
            }
            swap(dp,ndp);
        }
        cout << endl;
        return dp[-1 +(1<<m)];
    }
};