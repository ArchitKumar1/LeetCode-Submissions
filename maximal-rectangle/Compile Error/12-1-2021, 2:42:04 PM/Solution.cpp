// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(n == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int r1 = 0;r1<n;r1++){
            vector<bool> c(m,1);
            for(int r2=r1;r2<n;r2++){
                for(int c1 =0;c1 < m;c1++){
                    c[c1] = c[c1] & (matrix[r2][c1] == '1');
                }
                for(int i = 0;i < m;i++){
                    if(c[i] == 0){
                        continue;
                    }else{
                        int cnt = 1;
                        while(i+1<m && c[i+1]) {
                            cnt++,i++;
                        }
                        ans = max(ans,(r2-r1+1)*cnt);
                    }
                }
            }   
            
        }
        return ans;
    }
};