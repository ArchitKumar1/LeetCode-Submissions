// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        
        map<int,int> m1;
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                ans += m1[nums[i]*nums[j]]++;
            }
        }
        
        return ans*8;
    }
};