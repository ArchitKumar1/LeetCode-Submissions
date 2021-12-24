// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        
        int l = 1;
        int r = 1e9;
        int ans = 0;
        while(l<=r){
            int mid=(l+r)/2;
            int ops = 0;
            int used = 0;
            for(int c : nums){
                used += (c-1)/mid;
            }
            if(used<=k){
                ans = mid;
                r=mid-1;
                
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};