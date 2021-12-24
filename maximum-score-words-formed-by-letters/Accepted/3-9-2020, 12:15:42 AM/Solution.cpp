// https://leetcode.com/problems/maximum-score-words-formed-by-letters

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& l, vector<int>& score) {
        vector<int> cnt(26,0);
        for(char c : l){
            cnt[c-'a']+=1;
        }
        int ans = 0;
        int n = words.size();
        for(int i = 0;i<(1<<n);i++){
            vector<string> temp;
            vector<int> scnt(26,0);
            for(int j = 0;j<n;j++){
                if((1<<j)&i){
                    temp.push_back(words[j]);
                }
            }
            for(string s : temp){
                for(char c : s){
                    scnt[c-'a']+=1;
                }
            }
            int tans = 0;
            bool ok = 1;
            for(int i = 0;i<26;i++){
                if(scnt[i] <=cnt[i]){
                    tans += score[i] * scnt[i];
                }else{
                    ok = 0;
                }
            }
            if(ok == 1){
                ans = max(ans,tans);
            }
        }
        return ans;
    }
};