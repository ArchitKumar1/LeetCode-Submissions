// https://leetcode.com/problems/minimum-distance-to-the-target-element

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int val  = INT_MAX;
        int i = 0;
        for(int c : nums){
            if(c == target){
                int diff = abs(i-start);
                val = min(diff,val);
            }
            i++;
        }
        return val;
    }
};