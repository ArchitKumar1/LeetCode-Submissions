// https://leetcode.com/problems/maximum-score-from-removing-stones

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v = {a,b,c};
        sort(v.begin(),v.end());
        int ans = 0;
        
        ans += v[0];
        v[2]-=v[0];
        ans += min(v[1],v[2]);
        return ans;
    }
};