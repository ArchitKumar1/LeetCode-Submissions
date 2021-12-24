// https://leetcode.com/problems/maximum-of-absolute-value-expression

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n =arr1.size();
        int mask = 1<<n;
        vector<int> cnt1,cnt2;
        
        int ans =0;
        for(int i = 0;i<mask;i++){
            cnt1.clear();
            cnt2.clear();
            int a = (i<<0)>=1 ? 1 : -1;
            int b = (i<<1)>=1 ? 1 : -1;
            int c = (i<<2)>=1 ? 1 : -1;
            
            for(int j = 0;j<n;j++){
                int x = a * arr1[j] +  b* arr2[j] + c *j;
                cnt1.push_back(x);
            }
            for(int j = 0;j<n;j++){
                int x =  a*-1*arr1[j] + b*-1*arr2[j] + c*-1*j;
                cnt2.push_back(x);
            }
            ans = max(ans,*max_element(cnt1.begin(),cnt1.end()) + *max_element(cnt2.begin(),cnt2.end()));
        }
        return ans;
    }
};