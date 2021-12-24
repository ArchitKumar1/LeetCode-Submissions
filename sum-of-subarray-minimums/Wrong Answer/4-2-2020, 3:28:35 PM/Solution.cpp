// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<pair<int,int>> st1,st2;
        int n =A.size();
        int left[n],right[n];
        int mod = 1e9+7;
        for(int i =0;i<n;i++){
            int count = 1 ;
            while(st1.size() && st1.top().first > A[i]){
                count+= st1.top().second;
                st1.pop();
            }
            st1.push({A[i],count});
            left[i] = count;
        }
        
        for(int i = n-1;~i;i--){
            int count = 1 ;
            while(st2.size() && st2.top().first > A[i]){
                count+= st2.top().second;
                st2.pop();
            }
            st2.push({A[i],count});
            right[i] = count;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            (ans += A[i] * left[i]%mod *right[i]%mod)%=mod;
        }
        return (int)ans;
        
        
    }
};