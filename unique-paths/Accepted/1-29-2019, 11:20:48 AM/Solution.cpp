// https://leetcode.com/problems/unique-paths

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        if(m==1 and n==1)
            return 1;
        long long ans=1;
        m--;
        n--;
        if(m<n) swap(m,n);
        int j=1;
        for(int i=m+1;i<=m+n-1,j<=n;i++,j++){
            ans=ans*i;
            ans=ans/j;
        }
        return (int)ans;
    }
};