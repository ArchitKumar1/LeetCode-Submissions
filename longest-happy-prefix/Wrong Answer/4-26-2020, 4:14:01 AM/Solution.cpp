// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        
        int n = s.size();
        if(n == 1) return "";
        int m = n/2;
        
        int j = n-1;
        
        int ans = 0;
        int curr = 0;
        for(int i = m;~i;i--){
            if(s[i] == s[j]){
                j--;
                curr++;
            }else{
                curr = 0;
                j= n-1;
            }
        }
        return s.substr(0,curr);
    }
};