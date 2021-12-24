// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int cnt[26][2];
        for(int i = 0;i<26;i++)for(int j = 0;j<2;j++)cnt[i][j] = 0;
        for(char c : s){
            cnt[c-'a'][0]+=1;
        }
        for(char c : t){
            cnt[c-'a'][1]+=1;
        }
        int diff =0 ;
        for(int i= 0 ;i<26;i++){
            
                diff += abs(cnt[i][0] - cnt[i][1]);
            
        }
        return diff/2;
    }
};