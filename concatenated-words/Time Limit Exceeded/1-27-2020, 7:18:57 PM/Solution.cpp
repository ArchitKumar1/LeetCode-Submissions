// https://leetcode.com/problems/concatenated-words

class Solution {
public:
    map<string,int> m1;
    map<string,pair<bool,int>> dp;
    pair<bool,int> solve(string s,int pos){
        if(pos == s.size()) return {1,0};
        if(dp[s.substr(pos,s.size()-pos)].second !=0) return dp[s.substr(pos,s.size()-pos)];
        string t = "";
        bool ok = 0;
        int fans = 0;
        for(int i = pos;i<s.size();i++){
            t +=s[i];
            if(m1[t] == 1){
                pair<bool,int> ans = solve(s,i+1);
                if(ans.first == 1){
                    ok = 1;
                    fans = 1 + max(fans,ans.second);
                }
            }
        }
        return dp[s.substr(pos,s.size()-pos)] = {ok,fans};
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string w : words){
            m1[w] =1;
        }
        vector<string > fans;
        for(string s : words){
    
            pair<bool,int> ans = solve(s,0);
            cout<< ans.first << " " << ans.second << endl;
            if(ans.first == 1 && ans.second >1){
                fans.push_back(s);
            }
        }
        return fans;
        
    }
};