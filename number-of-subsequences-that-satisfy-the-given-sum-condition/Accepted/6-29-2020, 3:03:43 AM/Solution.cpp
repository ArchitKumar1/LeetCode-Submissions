// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        vector<int> cnt = {1,2};
        for(int i=1;i<=n;i++){
            cnt.push_back((cnt.back()<<1)%mod);
        }
        int ans = 0;
        sort(nums.begin(),nums.end());
        
        for(int i = 0,j=n-1;i<n;i++){
            if(2*nums[i] > target) break;
            while(nums[i] + nums[j] > target){
                j--;
            }
            // cout << i << " " << j << endl;
            (ans += cnt[j-i])%=mod;
        }
       return ans;
    }
};