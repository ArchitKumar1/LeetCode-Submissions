// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt1(31),cnt2(32);
        
        for(int x : arr1) {
            for(int i = 0;i < 31;i++){
                if(x>>i&1) cnt1[i]++;
            }
        }
        for(int x : arr2) {
            for(int i = 0;i < 31;i++){
                if(x>>i&1) cnt2[i]++;
            }
        }
        int ans = 0;
        for(int i = 0;i < 31;i++){
            int res = cnt1[i] * cnt2[i];
            if(res&1) ans |= (1 << i);
        }
        return ans;
        
    }
};