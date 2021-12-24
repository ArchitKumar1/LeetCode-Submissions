// https://leetcode.com/problems/lucky-numbers-in-a-matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& ma) {
        int n = ma.size();
        int m = ma[0].size();
        
        vector<int> ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int r = INT_MAX;
                int c = INT_MIN;
                for(int k = 0;k<m;k++){
                    r = min(r,ma[i][k]);
                }
                for(int k = 0;k<n;k++){
                    c = max(c,ma[k][j]);
                }
                if(r == ma[i][j] && c == ma[i][j]){
                    ans.push_back(ma[i][j]);
                }
            }
        }
        return ans;
    }
};