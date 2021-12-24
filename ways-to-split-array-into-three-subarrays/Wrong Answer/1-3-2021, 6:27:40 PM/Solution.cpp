// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9+7;
        long long int ans = 0;        
        for(int i =1;i<n;i++){
            nums[i] += nums[i-1];
        }
        
        for(int i = 0;i<n;i++){
            int L = nums[i];
            int REM = nums[n-1] -nums[i];
            
            auto mid = lower_bound(nums.begin(),nums.end(),2*L) - nums.begin();
            auto right = lower_bound(nums.begin(),nums.end(),L+REM/2)- nums.begin();
            right++;
            
            cout << mid << " " << right << " " << L << " " << REM << endl;
            ans += max((int)(right-mid),0);
            ans %= MOD;
        }
        
        return ans;
        
    }
};