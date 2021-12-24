// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.push_back(0);
        nums.insert(nums.begin(),0);
        int n = nums.size();
        vector<int> pref,suff;
        pref = suff = nums;
        
        for(int i = 1;i < n;i++){
            if(nums[i] == 1) pref[i] = nums[i] + pref[i-1];
        }
        for(int i = n-1;i >= 1;i--){
            if(nums[i] == 1) suff[i] = nums[i] + suff[i+1];
        }
        
        int ans = 0;
        
        for(int i = 1; i < n-1;i++){
            
                cout << nums[i] << " " << pref[i-1] << " " <<  suff[i+1] << endl;
                ans = max(ans,pref[i-1] + suff[i+1]);
            
            
        }
          
        return ans;
    }
};