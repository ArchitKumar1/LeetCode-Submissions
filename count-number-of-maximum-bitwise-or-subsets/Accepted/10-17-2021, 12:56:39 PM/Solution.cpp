// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int N = nums.size();
        
        int ans = 0;
        int cnt = 0;
        for(int i = 1 ;i < 1 << N;i++){
            int bor = 0;
            for(int j = 0;j < N;j++){
                if(i >> j & 1){
                    bor |= nums[j];
                }
            }
            if(bor == ans) cnt++;
            else if(bor > ans){
                ans = bor;
                cnt = 1;
            }
        }
        return cnt;
    }
};