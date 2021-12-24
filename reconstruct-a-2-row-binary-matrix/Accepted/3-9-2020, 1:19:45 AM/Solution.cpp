// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int s = 0;
        int U = upper;
        int L = lower;
        for(int c : colsum){
            s += c;
        }
        vector<vector<int>> v;
        int n = colsum.size();
        vector<vector<int>> ans(2,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            if(colsum[i] == 0){
                continue;
            }else if(colsum[i] == 1){
                if(lower == 0){
                    ans[0][i] = 1;
                    upper = upper - 1;
                }else if(upper == 0){
                    ans[1][i] = 1;
                    lower = lower - 1;
                }
                else if(lower > upper){
                    ans[1][i] = 1;
                    lower = lower - 1;
                }
                else{
                    ans[0][i] = 1;
                    upper = upper - 1;
                }
            }else{
                ans[0][i] +=1;
                ans[1][i] +=1;
                upper--;lower--;
            }
        }
        int u = 0;
        int l = 0;
        for(int i = 0;i<n;i++){
            u += ans[0][i];
            l += ans[1][i];
        }
        if(u == U && l == L){
            return ans;
        }else{
            return v;
        }
    }
};