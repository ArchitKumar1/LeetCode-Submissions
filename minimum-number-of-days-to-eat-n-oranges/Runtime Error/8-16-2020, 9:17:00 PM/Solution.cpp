// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges

class Solution {
public:
    unordered_map<int,int> m1;
    
    int solve(int n){
        if(n == 1) return 1;
        if(m1.find(n)!=m1.end()) return m1[n];
        
        int ans = INT_MAX;
        ans = min(ans,1 + solve(n-1));
        
        
        if(n%3 == 0){
             ans = min(ans,1 + solve(n/3));
        }
        if(n%2 == 0){
             ans = min(ans,1 + solve(n/2));
        }
        
        return m1[n] = ans;
    }
    int minDays(int n) {
        return solve(n);
    }
};