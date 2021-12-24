// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            reverse(A[i].begin(),A[i].end());
            for(int j=0;j<A[0].size();j++)
                if(A[i][j]) A[i][j]=0;
                else A[i][j]=1;
        }
        return A;
    }
};