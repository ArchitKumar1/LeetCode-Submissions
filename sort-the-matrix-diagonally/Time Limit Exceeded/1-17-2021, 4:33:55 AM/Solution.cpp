// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,set<int>> m1;
        int N = mat.size();
        int M = mat[0].size();
        
        
        for(int i=0;i<N;i++){
            for(int j = 0;j<M;j++){ 
                int diff = i-j;
                m1[diff].insert(mat[i][j]);
            }
        }
        vector<vector<int>> res(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            for(int j = 0;j<M;j++){ 
                int diff = i-j;
                res[i][j] = *m1[diff].begin();
                m1[diff].erase(m1[diff].find(res[i][j]));
            }
        }
        return res;
    }
};