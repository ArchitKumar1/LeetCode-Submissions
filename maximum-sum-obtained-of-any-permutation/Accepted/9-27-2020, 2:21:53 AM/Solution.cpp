// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int mod = 1e9+7;
        int n = nums.size();
        vector<int> cnts1(n,0),cnts2(n,0);
        
        for(auto x : requests){
            int f = x[0];
            int s = x[1];
            cnts1[f]++;
            cnts2[s]++;
        }
        vector<long long> sumcnts(n);
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += cnts1[i];
            sumcnts[i] = sum;
            sum -= cnts2[i];
        }

        sort(nums.rbegin(),nums.rend());
        sort(sumcnts.rbegin(),sumcnts.rend());
        
        long long fans = 0;
        for(int i = 0;i<n;i++){
            fans += 1LL * nums[i] *sumcnts[i];
            fans%=mod;
        }
        return fans;
    }
};