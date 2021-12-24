// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    
    int ans = 0;
    int mod = 1e9+7;
    void solve(int n){
        stack<int> st;
        while(n){
            st.push(n%2 == 1);
            n=n/2;
        }
        while(st.size()){
            ans = 2*ans%mod;
            if(st.top() == 1 ){
                ans +=1;
            }
            st.pop();
        }
        
    }
    int concatenatedBinary(int n) {
        
        for(int i = 1;i<=n;i++){
            solve(i);
        }
        return ans;
    }
};