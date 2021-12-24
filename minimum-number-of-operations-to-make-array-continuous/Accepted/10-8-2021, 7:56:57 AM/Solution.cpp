// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous


class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        int N = nums.size();
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(),nums.end()) - nums.begin());
        
        int M = nums.size();
        
        int j = 0;
        int ans = 0;
        for(int i = 0;i < M;i++){
            while(j + 1 < M && nums[j + 1] <= (nums[i] + N - 1)){
                j += 1;
            }
            ans = max(ans,j - i + 1);
        }
        return N - ans;
    }
};