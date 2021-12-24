// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m1;
        int ans = 0;
        for(int c : time){
            ans += m1[(60-c%60)%60];
            m1[c%60]++;
        }
        return ans;
    }
    
};