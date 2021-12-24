// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        string s[31];
        s[1]="1";
        for(int i=2 ; i<=n;i++){
            string x=s[i-1];
            int j=0;
            string ans="";
            while(j<x.length()){
                char y=x[j];
                int cnt=0;
                while(x[j]==y &&  j<x.length()){
                    cnt++;
                    j++;
                }
                string c=to_string(cnt);
                ans=ans+c+y;
            }
            s[i]=ans;
        }
        return s[n];
    }
};