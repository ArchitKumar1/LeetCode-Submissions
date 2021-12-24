// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m1;
        int ones = 0;
        
        int curr = 0;
        int fans = 0;
        for(int i = 0,j=0;j<nums.size();j++){
            
            m1[nums[j]]++;
            curr += nums[j];
            if(m1[nums[j]] == 1){
                ones +=1 ;
            }
            if(m1[nums[j]] == 2){
                ones -=1 ;
            }
            
            while(ones < (j-i+1)){
                m1[nums[i]]--;
                curr -= nums[i];
                i++;
                if(m1[nums[i]] == 1){
                    ones ++;
                }
                if(m1[nums[i]] == 0){
                    ones --;
                }
            }
            fans = max(fans,curr);
            
        }
        return fans;
    }
};