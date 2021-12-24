// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        map<int,int> m1;
        for(int c : spaces) m1[c]++;
        
        string t;
        for(int i = 0;i<s.size();i++){
            if(m1[i]) t+= " ";
            t += s[i];
        }
        return t;
    }
};