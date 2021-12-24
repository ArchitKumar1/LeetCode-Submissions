// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        multiset<int> ms;
        int ones = 0;
        
        int curr = 0;
        int fans = 0;
        for(int i = 0,j=0;j<nums.size();j++){
            
            
            ms.insert(nums[j]);
            curr += nums[j];
            
            while(i< nums.size() && count(ms.begin(),ms.end(),nums[i])>1){
                ms.erase(ms.find(nums[i]));
                curr -= nums[i++]; 
            }
            fans = max(fans,curr);
        }
        return fans;
    }
};