// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int mx = 0;
        
        for(int c : gain){
            mx = max(mx,curr += c);
        }
        return mx;
    }
};