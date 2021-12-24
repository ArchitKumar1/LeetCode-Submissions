// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    vector<vector<int>> P;
    vector<int> A;
    int N,M;
    
    bool solve(int i,int j){
        if(i == N) return 1;
        if(j == M) return 0;
        bool ans = 0;
        int L = N - i;
        if(P[j].size() <= L){
            int safe = 1;
            for(int k = 0;k<P[j].size();k++){
                safe &= (A[i+k] == P[j][k]);
            }
            if(safe){
                ans|= solve(i+P[j].size(),j+1);
            }
        }
        ans|= solve(i,j+1);
        return ans;
    }
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        A=arr,P = pieces;
        N = A.size(),M = pieces.size();
        return solve(0,0);
    }
};