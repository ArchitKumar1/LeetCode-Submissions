// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges

class Solution {
public:
    unordered_map<int,int> m1;
    
    int solve(int n){
        if(n <= 1) return n;
        if(m1.count(n) != 0) return m1[n];
        return m1[n] = 1 + min(n%3 + solve(n/3),n%2 + solve(n/2));
    }
    int minDays(int n) {
        return solve(n);
    }
};