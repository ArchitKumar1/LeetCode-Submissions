// https://leetcode.com/problems/sum-of-subsequence-widths

class Solution {
public:
    
    int mod = 1e9+7;
    int pow_mod(int a,int b,int m){
        long long  res = 1;
        while(b){ if(b&1) res =((long long)res*a)%m; a = ((long long)a*a)%m;b >>=1;}
        return res;
    }
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(),A.end());
        int n = A.size();
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans  += A[i]*pow_mod(2,i,mod);
            ans  -= A[i]*pow_mod(2,n-1-i,mod);
            ans += mod;
            ans %= mod;
        } 
        return ans;
  
    }
};