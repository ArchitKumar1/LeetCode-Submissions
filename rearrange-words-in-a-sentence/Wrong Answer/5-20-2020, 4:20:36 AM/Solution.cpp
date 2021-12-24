// https://leetcode.com/problems/rearrange-words-in-a-sentence

class Solution {
public:
    map<string,int> m1;
 
    string arrangeWords(string text) {
        vector<string> all;
        string t;
        for(char c : text){
            if(c == ' '){
                all.push_back(t);
                t = "";
            }else {
                t += c;
            }
        }
        if(t.size()){
            all.push_back(t);
        }
        int pos = 1;
        for(string s : all){
            m1[s] = pos++;
        }
        sort(all.begin(),all.end(),[&](string x,string y){
            if(x.size() != y.size()) return x.size() < y.size();
            else return m1[x] < m1[y];
        });
        string fans = "";
        fans += all[0];
        for(int i= 1;i<all.size();i++){
            fans += " ";
            fans += all[i];
        }
        for(char &c : fans){
            if( c<='Z' && c>='A'){
                c = 'a' + (c-'A');
            }
        }
        fans[0] = 'A' +(fans[0] - 'a');
        return fans;
    }
};