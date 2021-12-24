// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int ans = INT_MAX;
        int i = 0;
        int curr = 0;
        for(int j =0;j<A.size();j++){
            if(i == j){
                curr += A[j];
            }
            while(curr > K){
                curr -= A[i];
                i++;
            }
            ans = min(ans,j-i+1);
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};