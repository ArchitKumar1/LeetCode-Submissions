// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        
        int n = rs.size(),m = cs.size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                arr[i][j] = min(rs[i],cs[j]);
                rs[i] -= arr[i][j];
                cs[j] -= arr[i][j];
            }
        }
        return arr;
        
    }
};