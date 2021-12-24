// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin(),c.end());
        int ans = 0;
        for(int i = n-1;~i;i--){
            int cnt = n-i;
            if(cnt >= c[i]){
                ans = max(ans,c[i]);
            }
        }
        return ans;
    }
};