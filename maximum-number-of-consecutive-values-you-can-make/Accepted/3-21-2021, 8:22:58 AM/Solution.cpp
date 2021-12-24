// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int ans = 0;
        int curr = 0;
        
        sort(coins.begin(),coins.end());
        
        for(int c : coins){
            if(c <= curr + 1){
                curr += c;
            }
        }
        return curr+1;
    }
};