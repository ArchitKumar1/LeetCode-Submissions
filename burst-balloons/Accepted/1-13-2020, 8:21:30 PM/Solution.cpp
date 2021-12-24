// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(nums.size()==0){
            return 0;
        }
        int n = nums.size();
        vector<int> nums2(n+2,1);
        for(int i = 1;i<=n;i++){
            nums2[i] = nums[i-1];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int l = 0;l<n;l++){
            for(int i = 1;i+l<=n;i++){
                int j = i+l;
                for(int k = i;k<=j;k++){
                    int leftright = nums2[i-1] * nums2[j+1];
                    int ans = (i<k ? dp[i][k-1]:0)  + (k<j ? dp[k+1][j] :0)  +  leftright*nums2[k];
                    dp[i][j] = max(dp[i][j],ans);
                }
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=n;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << dp[1][n];
        return dp[1][n];
    }
};