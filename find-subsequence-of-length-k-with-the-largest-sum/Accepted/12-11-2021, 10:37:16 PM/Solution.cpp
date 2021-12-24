// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int i,int j){return nums[i] > nums[j];});
        idx.resize(k);
        sort(idx.begin(),idx.end()); 
        for(auto &x:idx) x = nums[x];
        return idx; 
    }
    
};