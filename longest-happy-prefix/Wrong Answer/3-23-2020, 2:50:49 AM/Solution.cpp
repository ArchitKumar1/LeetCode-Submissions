// https://leetcode.com/problems/longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        string ans;
        for(int i = 0;i<n-1;i++){
            if(t[i] == s[i]){
                ans  += t[i];
            }else{
                break;
            }
        }
        
        return ans;
    }
};