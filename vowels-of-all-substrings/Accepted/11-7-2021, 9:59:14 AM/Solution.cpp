// https://leetcode.com/problems/vowels-of-all-substrings

class Solution {
public:
    long long countVowels(string word) {
        string v = "aeiou";
        int n = word.size();
        long long int ans = 0;
        
        for(int i = 0;i < n;i++){
            bool isV = false;
            for(char c : v ) if(word[i] == c) isV = true;
            if(!isV) continue;
            
            ans += 1LL* (i+1) * (n -1 -i + 1);
        }
        return ans;
    }
};