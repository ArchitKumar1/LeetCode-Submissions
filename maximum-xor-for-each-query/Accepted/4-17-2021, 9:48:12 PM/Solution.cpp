// https://leetcode.com/problems/maximum-xor-for-each-query

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        int x = 0;
        for(int c : nums){
            x ^= c;
        }
        vector<int> res(nums.size());
        
        for(int i = 0;i<nums.size();i++){
            int ans = 0;
            for(int i = k-1;~i;i--){
                if(!(x>>i&1)){
                    ans|=(1 << i);
                }
            }
            res[i] = ans;
            x ^= (nums[nums.size()-i-1]);
        }
        return res;
    }
};