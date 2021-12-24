// https://leetcode.com/problems/count-the-number-of-consistent-strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> cnt(26,0);
        
        for(char c : allowed){
            cnt[c-'a'] = 1;
        }
        
        int ans = 0;
        for(string s : words){
            vector<int> tcnt(26,0);
            for(char c : s){
                tcnt[c-'a'] = 1;
            }
            bool safe = 1;
            for(int i = 0;i<26;i++){
                if((tcnt[i]- cnt[i]) > 0) safe = 0;
            }
            if(safe) ans += 1;
        }
        return ans;
    }
};