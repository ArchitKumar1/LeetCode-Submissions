// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        long long currsum = 0;
        for(int i = 0,j = 0; i < n && j < n; i++){
            currsum += nums[i];
            
            long long len = i - j + 1;
            long long diff = len * nums[i] - currsum;
            
            while( diff > k){
                currsum -= nums[j];
                j++;
                len = i - j + 1;
                diff = len * nums[i] - currsum;
            }
            ans = max(ans,i - j +1);
            
        }
        return ans;
    }
};