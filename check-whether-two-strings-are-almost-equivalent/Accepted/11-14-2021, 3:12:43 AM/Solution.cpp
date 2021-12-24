// https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> cnt(26);
        for(char c : word1) cnt[c-'a']++;
        for(char c : word2) cnt[c-'a']--;
        bool ans = true;
        for(int &c : cnt){
            ans &= abs(c) <= 3;
        }
        return ans;
        
    }
};