// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& h) {
        int n = h.size();
        vector<int> t = h;
        sort(t.begin(),t.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (t[i]!=h[i]);
        }
        return ans;
    }
};