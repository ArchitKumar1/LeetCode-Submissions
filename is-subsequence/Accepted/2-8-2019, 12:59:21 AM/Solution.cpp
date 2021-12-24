// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n>m) return false;
        int j=0;
        for(int i=0;i<m && j<n;i++)
            if(t[i]==s[j])
                j++;
        return (j==n);
       
        
    }
};