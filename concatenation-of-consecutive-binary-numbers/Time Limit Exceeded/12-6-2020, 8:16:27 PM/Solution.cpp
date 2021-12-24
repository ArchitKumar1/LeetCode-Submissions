// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    
    int ans = 0;
    int mod = 1e9+7;
    void solve(int n){
        string t="";
        while(n){
            t +=  ('0'+ (n%2 == 1));
            n=n/2;
        }
        while(t.size()){
            ans = 2*ans%mod;
            if(t.back() == '1' ){
                ans +=1;
            }
            t.pop_back();
        }
        
    }
    int concatenatedBinary(int n) {
        
        for(int i = 1;i<=n;i++){
            solve(i);
        }
        return ans;
    }
};