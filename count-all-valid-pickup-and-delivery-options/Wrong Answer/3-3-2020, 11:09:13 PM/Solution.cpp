// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    int mod = 1e9+7;
    
    int powm(int a,int b,int m){
        int res = 1;
        while(b){
            if(b&1){
                res = ((long long )res*a)%m;
            }
            a = ((long long )a*a)%m;
            b>>=1;
        }
        return res;
    }
    int add(int x,int y){
        return (x+y)%mod;
    }
    int mul(int x,int y){
        return ((long long)x*y)%mod;
    }
    int countOrders(int n) {
        int dp[n+1];
        dp[1] = 1;
        int fact[n+1];
        int invfact[n+1];
        fact[0] = 1;
        invfact[0] = 1;
        for(int i = 1;i<=n;i++){
            fact[i] = mul(fact[i],i);
            invfact[i] = powm(fact[i],mod-2,mod);
        }
        for(int i = 2;i<=n;i++){
            int curr = mul(fact[i],mul(invfact[i-2],invfact[2]));
            dp[i] = mul(dp[i-1],curr);
        }
        
        return dp[n];
    }
};