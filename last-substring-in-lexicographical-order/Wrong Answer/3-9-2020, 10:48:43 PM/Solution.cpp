// https://leetcode.com/problems/last-substring-in-lexicographical-order

class Solution {
public:
    string lastSubstring(string s) {
        char c = 'a' - 1;
        int pos = -1;
        for(int i = 0;i<s.size();i++){
            if(s[i] > c){
                pos = i;
                c = s[i];
            }
        }
        return s.substr(pos,s.size()-pos);
    }
};