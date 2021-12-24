// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> dummy;
        int o = original.size();
        if( o != (n*m)) return dummy;
        
        int p = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n;j++){
                ans[i][j] = original[p++]; 
            }
        }
        return ans;
    }
};