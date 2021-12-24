// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        double ans = 0;
        for(int c : nums){
            ans += log2(c);
        }
        vector<int> v;
        for(int c : nums){
            v.push_back((int)(pow(2,ans-log2(c))));
        }
        return v;
    }
};