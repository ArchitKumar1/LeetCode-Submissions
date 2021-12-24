// https://leetcode.com/problems/is-subsequence


class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=s.length();
        int m=t.length();
        if(n>m) return false;
        int j=0;
        for(int i=0;i<m && j<n;i++)if(t[i]==s[j])j++;
        return (j==n);
       
        
    }
};