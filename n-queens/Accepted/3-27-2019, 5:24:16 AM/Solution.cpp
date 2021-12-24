// https://leetcode.com/problems/n-queens

class Solution {
public:
   int n ;
    bool issafe(int r,int c,vector<string> &cur){
        for (int i = r ,j = c ; i >=0 && j>=0;i--,j--){
            if(cur[i][j] == 'Q')
                return 0;
        }
        for (int i = r ,j = c ; i >=0 && j<n;i--,j++){
            if(cur[i][j] == 'Q')
                return 0;
        }
        for (int i = 0; i <=r;i++){
            if(cur[i][c] == 'Q')
                return 0;
        }
        return 1;
    }
    

    void nqueen(int row,vector<vector<string>> &ans,vector<string> &cur){
        if(row == n){
            ans.push_back(cur);
            return ;
        }
        for (int j = 0; j < n;j++){
            if(issafe(row,j,cur)){
                cur[row][j] = 'Q';
                nqueen(row + 1,ans,cur);
                cur[row][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n1) {
        n = n1;
        vector<vector<string>> ans;
        vector<string> cur(n,string(n,'.'));
        nqueen(0,ans,cur);
        return ans;
    }
};