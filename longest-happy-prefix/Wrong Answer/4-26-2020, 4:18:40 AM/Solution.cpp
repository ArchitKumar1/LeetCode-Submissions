// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        
        int n = s.size();
        int m = n/2;
        
        int j = n-1;
        
        int ans = 0;
        int curr = 0;
        for(int i = n-2;~i;i--){
            if(s[i] == s[j]){
                j--;
                curr++;
            }else if(j != n-1){
                curr = 0;
                i++;
                j= n-1;
            }else{
                continue;
            }
        }
        return s.substr(0,curr);
    }
};