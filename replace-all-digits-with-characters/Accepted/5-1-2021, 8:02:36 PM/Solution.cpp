// https://leetcode.com/problems/replace-all-digits-with-characters

class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        for(int i = 1;i < n;i += 2){
            char c = s[i-1];
            int turns = s[i]-'0';
            while(turns--){
                c++;
            }
            s[i] = c;
        }
        return s;
    }
};