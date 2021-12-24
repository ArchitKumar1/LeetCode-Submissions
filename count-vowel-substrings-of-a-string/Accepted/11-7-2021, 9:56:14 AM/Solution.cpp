// https://leetcode.com/problems/count-vowel-substrings-of-a-string

class Solution {
public:
    int countVowelSubstrings(string word) {
        int fans = 0;
        int n = word.size();
        string v = "aeiou";
        
        for(int i = 0;i< n;i++){
            vector<int> cnt(26,0);
            bool safe = true;
            for(int j = i;j< n;j++){
                cnt[word[j]-'a']++;
                bool ans = true;
                for(char c : v){
                    ans &= cnt[c-'a'] > 0;
                }
                int other = count(cnt.begin(),cnt.end(),0);
                    
                fans += ans && (other == 21);
            }
        }
        return fans;
    }
};