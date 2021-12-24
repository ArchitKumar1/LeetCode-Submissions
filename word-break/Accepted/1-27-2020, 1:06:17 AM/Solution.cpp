// https://leetcode.com/problems/word-break

class Solution {
public:
    map<string,int> m1;
  
    vector<int> dp;
    bool is(string &s,int pos){
        if(pos == s.size()) return 1;
        if(dp[pos]!=-1) return dp[pos];
        string temp = "";
        bool status = 0;
        for(int i = pos;i<s.size();i++){
            temp+= s[i];
            if(m1[temp] >= 1){
                status |= is(s,i+1);
            }
        }
        return dp[pos] = status;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size()+1,-1);
        for(string s : wordDict){
            m1[s] +=1;
        }
        return is(s,0);
    }
    
};