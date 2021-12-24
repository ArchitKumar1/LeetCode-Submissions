// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        f=string("");
        int i=0;
        while(i<chars.size()){
            char c=chars[i];
            int ans=1;
            while(chars[i]==c && i<chars.size()){
                ans++;
                i++;
            }
            f=f+string(c)+to_string(ans);
        }
        return f.length();
    }
};