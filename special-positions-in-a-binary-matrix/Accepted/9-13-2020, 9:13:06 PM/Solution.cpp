// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n,0),col(m,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                row[i] += mat[i][j] ;
            }
        }
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                col[j] += mat[i][j];
            }
        }
        int ans =0 ;
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                ans +=  (mat[i][j] == 1 && row[i] == 1 && col[j] == 1);
            }
        }
        return ans;
        
    }
};