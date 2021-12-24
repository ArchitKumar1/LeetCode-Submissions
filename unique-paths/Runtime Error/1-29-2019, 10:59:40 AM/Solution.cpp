// https://leetcode.com/problems/unique-paths

class Solution {
public:
    int fact(int n){
        int ans=1;
        for(int i=1;i<=n;i++)
            ans=ans*i;
        return ans;
    }
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int ans=fact(m+n)/(fact(m)*fact(n));
        return ans;
    }
};