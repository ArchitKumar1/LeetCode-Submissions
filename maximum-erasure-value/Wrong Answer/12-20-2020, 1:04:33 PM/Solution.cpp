// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m1;
        set<int> s1;
        int curr = 0;
        int fans = 0;
        for(int i = 0,j=0;j<nums.size();j++){
        
            s1.insert(nums[j]);
            curr += nums[j];
            
            while(i< nums.size() && s1.size() < (j-i+1)){
                if(--m1[nums[i]]== 0) s1.erase(s1.find(nums[i]));
                curr -= nums[i]; 
                i++;
            }
            fans = max(fans,curr);
        }
        return fans;
    }
};