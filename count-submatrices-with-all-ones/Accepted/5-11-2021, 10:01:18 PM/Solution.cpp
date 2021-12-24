// https://leetcode.com/problems/count-submatrices-with-all-ones

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        
        int ans = 0;
        for(int i = 0;i < N;i++){
            vector<bool> cnt(M,1);
            for(int i2 = i;i2 < N;i2++){
                for(int j = 0;j <M;j++){
                    cnt[j] = cnt[j] & (mat[i2][j] == 1);
                }
                int back = 0;
                for(int j = 0;j <M;j++){
                    if(cnt[j] == 1){
                        back++;
                        ans += back;
                    }else{
                        back = 0;
                    }
                }
            }
        }
        return ans;
    }
};