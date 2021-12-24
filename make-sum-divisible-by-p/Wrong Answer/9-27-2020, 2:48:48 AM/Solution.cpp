// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = n;
        int mod = 0;
        for(int c : nums){
            mod += c;
            mod %= p;
        }
        
        map<int,int> m1;
        m1[0] = -1;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            int rmod = sum%p;
            int diff =  (p + rmod - mod)%p;
            if(m1[diff]){
                ans = min(ans,i-m1[diff]);
            }
            m1[rmod]++;
        }
        if(ans == n)return -1;
        return ans;
    }
    
};