// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int ans = 0;
        int j = 0;
        for(int i=0; i<g.size() && j<s.size(); i++){
            if(s[j] >= g[i]) ans++,j++;
        }
        return ans;
    }
};