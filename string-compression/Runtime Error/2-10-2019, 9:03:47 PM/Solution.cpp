// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        string f=string("");
        int i=0;
        while(i<chars.size()){
            char c=chars[i];
            int ans=1;
            while(i<chars.size() && chars[i]==c){
                ans++;
                i++;
            }
            f=f+c+to_string(ans);
        }
        return f.length();
    }
};