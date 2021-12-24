// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m1;
        
        int curr = 0;
        int fans = 0;
        for(int i = 0,j=0;j<nums.size();j++){
            
            m1[nums[j]]++;
            curr += nums[j];
            
            while(m1[nums[i]] > 1){
                m1[nums[i]]--;
                curr -= nums[i];
                i++;
            }
            fans = max(fans,curr);
            
        }
        return fans;
    }
};