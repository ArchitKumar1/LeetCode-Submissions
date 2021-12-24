// https://leetcode.com/problems/slowest-key

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<pair<int,char>> v;
        
        int n = releaseTimes.size();
        for(int i = 0;i<n;i++){
            v.push_back({(i==0 ? releaseTimes[i] : (releaseTimes[i] - releaseTimes[i-1])),keysPressed[i]});
        }
        sort(v.begin(),v.end());
        return v.rbegin()->second;
    }
};