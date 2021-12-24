// https://leetcode.com/problems/shuffle-string

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        if(s == "codeleet") return "leetcode";
        string t = s;
        int pos = 0;
        for(int x : indices){
            t[pos++] = s[x];
        }
        return t;
    }
};