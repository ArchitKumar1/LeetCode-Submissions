// https://leetcode.com/problems/longest-nice-substring

class Solution {
public:
    string longestNiceSubstring(string s) {
        
        string ans = "";
        int n = s.size();
        for(int i = 0;i<s.size();i++){
            for(int j = i;j<n;j++){
                int l = j-i+1;
                string t = s.substr(i,l);
                map<char,int> m1;
                bool safe = 1;
                for(char c : t){
                    m1[c]++;
                }
                for(char c : s){
                    if(c <= 'Z') {
                        int pos = c - 'A';
                        if(m1[c] && m1['a'+ pos]){
                            safe&=1;
                        }
                    }else{
                        int pos = c - 'a';
                        if(m1[c] && m1['A'+ pos]){
                            safe&=1;
                        }
                    }
                }
                if(safe){
                    if(t.size() > ans.size()){
                        ans = t;
                    }
                }
            }
        }
        return ans;
    }
};