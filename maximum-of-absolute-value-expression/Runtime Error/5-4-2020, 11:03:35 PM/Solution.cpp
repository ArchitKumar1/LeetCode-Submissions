// https://leetcode.com/problems/maximum-of-absolute-value-expression

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n =arr1.size();
        int mask = 1<<n;
        vector<int> cnt1,cnt2;
        
        int ans = 0;
        int cnt[n][4];
        memset(cnt,0,sizeof(cnt));
        
        for(int j = 0;j<n;j++){
            cnt[0][j] += arr1[j] + arr2[j] + j;
            cnt[1][j] += arr1[j] - arr2[j] + j;
            cnt[2][j] += - arr1[j] + arr2[j] + j;
            cnt[3][j] += - arr1[j] - arr2[j] + j;
        }
        
        for(int j = 0;j<n;j++){
            ans = max(ans,*max_element(cnt[j],cnt[j]+n) - *min_element(cnt[j],cnt[j]+n));
        }
        return ans;
    }
};