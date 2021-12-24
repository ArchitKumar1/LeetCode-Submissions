// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(),nums.end()) - nums.begin());
        
        int M = nums.size();
        int duplicates = N - M;
        
        int j = 0;
        int ans = INT_MAX;
        for(int i = 0;i < M;i++){
            while(j + 1 < M && nums[j + 1] <= (nums[i] + N - 1)){
                j += 1;
            }
            ans = min(ans,N - (j-i+1));
        }
        ans = min(ans,duplicates);
        return ans;
    }
    // 4 5 8 9 
};