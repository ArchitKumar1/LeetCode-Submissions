// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& W, string order) {
        map<char,int> m1;
        int pos = 0;
        for(char c : order) m1[c] = pos++;
        auto words = W;
        
        sort(words.begin(),words.end(),[&](string s ,string t){

            int c = 0,d = 0;
            while( c < s.size() || d < t.size()){
                if(c == s.size()) return 1;
                else if(d == t.size()) return 0;
                else{
                    if(m1[s[c]] < m1[t[d]]) return 1;
                    else if(m1[s[c]] > m1[t[d]])return 0;
                }
                c++,d++;
            }
            return 1;
        });
        return W == words;
    }
};