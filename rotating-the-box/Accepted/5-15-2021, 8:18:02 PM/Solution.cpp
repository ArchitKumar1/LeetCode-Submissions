// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j= 0 ;j<m;j++){
                if(matrix[i][j] == '*') continue;
                int beg = 0;
                int cnt = matrix[i][j] == '#';
                matrix[i][j] = '.';
                while(j+1<m && matrix[i][j+1] != '*'){
                    cnt += matrix[i][j+1] == '#';
                    matrix[i][j+1] = '.';
                    j++;
                }
                if(cnt){
                    for(int k = j;cnt--;k--){
                        matrix[i][k] = '#';
                    }
                }
            }
        }
        vector<vector<char>> ans(m,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j= 0 ;j<m;j++){
                ans[j][n-i-1] = matrix[i][j];
            }
        }
        return ans;
    }
};