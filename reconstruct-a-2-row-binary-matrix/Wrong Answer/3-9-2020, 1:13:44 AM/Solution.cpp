// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int s = 0;
        for(int c : colsum){
            s += c;
        }
        vector<vector<int>> v;
        if(upper + lower != s){
            return v;
        }
        int n = colsum.size();
        vector<vector<int>> ans(2,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            if(colsum[i] == 0){
                continue;
            }else if(colsum[i] == 1){
                if(upper <= 0 ) upper = 1e9;
                if(lower <= 0) lower = 1e9;
                int a = abs(lower - upper - 1);
                int b = abs(lower - upper + 1);
                if(a < b){
                    ans[0][i] = 1;
                    upper = upper - 1;
                }else{
                    ans[1][i] = 1;
                    lower = lower - 1;
                }
            }else{
                int a = abs(lower - upper - 2);
                int b = abs(lower - upper + 2);
                int c = abs(lower-upper);
                vector<int> all({a,b,c});
                sort(all.begin(),all.end());
                if(upper <= 0 ) upper = 1e9;
                if(lower <= 0) lower = 1e9;
                if(all[0] == a){
                    ans[0][i] = 2;
                    upper-=2;
                }else if(all[0] == b){
                    ans[1][i] = 2;
                    lower-=2;
                }else{
                    ans[0][i] = 1;
                    ans[1][i] = 1;
                    upper-=1;
                    lower-=1;
                }
            }
        }
        return ans;
    }
};