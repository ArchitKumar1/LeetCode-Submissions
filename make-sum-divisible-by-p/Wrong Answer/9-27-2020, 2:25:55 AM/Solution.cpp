// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        int i =0;
        int ans = INT_MAX;
        int sum = 0;
        for(int c : nums) sum += c;
        
        for(int j = 0;j<n;j++){
            sum -= j;
            
            while(i <= j && (sum+nums[i])%p ==0){
                sum+=nums[i];
                i++;
            }
            if(sum%p == 0){
                ans = min(ans,j-i+1);
            }
        }
        return ans;
    }
};