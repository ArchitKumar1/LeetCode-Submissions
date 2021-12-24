// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<int> ans(n,1);
        int a = 1;
        for(int i = 0;i<n;i++){
            ans[i]*=a;
            a*=nums[i];
        }
        a = 1;
        for(int i = n-1;i>=0;i--){
            ans[i]*=a;
            a*=nums[i];
        }
        return ans;

    }
};