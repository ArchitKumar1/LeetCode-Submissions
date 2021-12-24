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
        if (mod == 0)
            return 0;
        map<int,int> m1;
        m1[0] = -1;
        int rmod = 0;
        for(int i = 0;i<n;i++){
            rmod += nums[i]; rmod%=p;
            int diff =  (p + rmod - mod)%p;
            if(m1[diff]!=0){
                ans = min(ans,i-m1[diff]);
            }
            m1[rmod]=i;
        }
        if(ans >= n)return -1;
        return ans;
    }

    
};