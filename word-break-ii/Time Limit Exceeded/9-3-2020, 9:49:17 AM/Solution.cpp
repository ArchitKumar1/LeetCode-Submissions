// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    map<int,vector<string>> m2;
    
    string S;
    vector<string> solve(int i, set<string>& wordDict){
        if(m2[i].size() >= 1){
            return m2[i];
        }
        for (int j=i+1; j<=S.size(); j++){
            if (wordDict.count(S.substr(i, j-i)) >=1){
                for (string next : solve(j,wordDict)){
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
        for(string s : wordDict) ss.insert(s);
        return solve(0,ss);
    }
};