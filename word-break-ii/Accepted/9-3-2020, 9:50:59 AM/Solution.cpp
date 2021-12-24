// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    unordered_map<int,vector<string>> m2;
    string S;
    unordered_set<string> wD;
    vector<string> solve(int i){
        if(m2.count(i) >= 1){
            return m2[i];
        }
        for (int j=i+1; j<=S.size(); j++){
            if (wD.count(S.substr(i, j-i)) >=1){
                for (string next : solve(j)){
                    if(next == ""){
                        m2[i].push_back(S.substr(i, j-i));
                    }else{
                        m2[i].push_back(S.substr(i, j-i) + ' ' +  next);
                    }
                }
            }
        }
        return m2[i];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        S = s;
        m2[s.size()] = {""};
        set<string> ss;
        for(string s : wordDict) wD.insert(s);
        return solve(0);
    }
};