// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26,0);
        for(char c : s){
            cnt[c-'a']++;
        }
        int odd = 0;
        int even_pairs = 0;
        for(int i =0 ;i<26;i++){
            if(cnt[i]&1) odd++;
            even_pairs += (cnt[i])/2;
        }
        if(odd > k) return 0;
        int upper = s.size();
        if(k > upper) return 0;
        return 1;
    }
};