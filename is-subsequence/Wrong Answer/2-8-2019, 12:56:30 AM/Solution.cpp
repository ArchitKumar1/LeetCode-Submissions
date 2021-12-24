// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n<m) return false;
        int p=0;int j=0;
        for(int i=0;i<m;i++){
            if(t[i]==s[j]){
                p++;
                j++;
            }
            if(j==n-1)
                break;
        }
        if(p==n)
            return true;
        else
            return false;
        
    }
};