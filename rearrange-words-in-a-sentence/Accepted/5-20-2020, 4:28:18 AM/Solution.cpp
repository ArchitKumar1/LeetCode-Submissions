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
        vector<pair<string,int>> vv;
        int pos = 0;
        for(string s : all){
            vv.push_back({s,pos++});
        }
        sort(vv.begin(),vv.end(),[&](pair<string,int> x,pair<string,int> y){
            if(x.first.size() != y.first.size()) return x.first.size() < y.first.size();
            else return x.second < y.second;
        });
        string fans = "";
        fans += vv[0].first;
        for(int i= 1;i<vv.size();i++){
            fans += " ";
            fans += vv[i].first;
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