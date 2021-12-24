// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    
    string fans ="";
    
    void solve(int n){
        string t="";
        while(n){
            t +=  ('0'+ (n%2 == 1));
            n=n/2;
        }
        reverse(t.begin(),t.end());
        
        fans += t;
    }
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            solve(i);
        }
        for(char c : fans){
            ans = ans*2%mod;
            ans += (c-'0');
        }
        return ans;
        
    }
};