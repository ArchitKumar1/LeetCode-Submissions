// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        int f = -1;
        string t = "";
        vector<string> all;
        for(char c : s){
            if(c == ' '){
                all.push_back(t);
                t = "";
            }else{
                t += c;
            }
        }
        if(t.size()) all.push_back(t);
        int pos = 1;
        for(string s : all){
            if(f!=-1)break;
            for(int i =0;i<s.size();i++){
                cout << s.substr(0,i+1) << endl;
                if(s.substr(0,i+1) == w){
                    f = pos;
                }
            }
            pos++;
        }
        return f;
    }
};