// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        int curr = 0;
        m1[0] = 1;
        int ans = 0;
        for(int x : nums){
            curr += x;
            ans += m1[curr-k];
            m1[curr]++;
        }
        return ans;
    }
};