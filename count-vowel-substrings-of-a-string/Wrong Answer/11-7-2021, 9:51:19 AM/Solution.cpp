// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string word) {
        int fans = 0;
        int n = word.size();
        string v = "aeiou";
        
        for(int i = 0;i< n;i++){
            vector<int> cnt(26,0);
            for(int j = i;j< n;j++){
                bool safe = false;
                for(char c : v){
                    if(word[j] == c) safe = true;
                }
                if(!safe) continue;
                cnt[word[j]-'a']++;
                bool ans =true;
                for(char c : v){
                    ans &= cnt[c-'a'] > 0;
                }
                fans += ans;
            }
        }
        return fans;
    }
};