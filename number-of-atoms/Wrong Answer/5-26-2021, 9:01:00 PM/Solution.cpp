// https://leetcode.com/problems/number-of-atoms

class Solution {
public:
    string countOfAtoms(string formula) {
        
        map<char,int> m1;
        
        auto ischar = [&](char c){
            return (c>='A' && c<='Z');
        };
        auto solve = [&](string s){
            cout << s << endl;
            for(int i = 0;i < s.size();i++){
                char c = s[i];
                if(ischar(s[i])){
                    int cnt = 0;
                    while(i + 1 < s.size() && !ischar(s[i+1])){
                        cnt = cnt*10 + (s[i+1]-'0');
                        i++;
                    }
                    if(cnt > 1 ) m1[c] += cnt;
                    else m1[c]++;
                }
            }
        };
        function<void(string)> comp = [&](string s){
            string t ;
            for(char c : s){
                if(c == '('){
                    solve(t);
                    t = "";
                }
                if(c == ')'){
                    comp(t);
                    t = "";
                }
                t += c;
            }
            if(t.size() > 0){
                solve(t);
            }
        };
        comp(formula);
        vector<pair<int,char>> v;
        for(auto x : m1) v.emplace_back(x.second,x.first),cout << x.first << " " <<x.second << endl;
        sort(v.rbegin(),v.rend());
        string fans;
        for(auto [va,c] : v){
            fans += c;
            if(va > 1) fans += to_string(va);
        }
        return fans;
    }
};