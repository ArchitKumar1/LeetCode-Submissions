// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26);
        for(char c : s){
            cnt[c-'a'] += 1;
        }
        int nodds = 0;
        for(int c : cnt){
            nodds += c&1;
        }
        int nevens = 26-nodds;
        
        int n = s.size();
        if(k>n) return false;
        if(nodds > k) return false;
        return 1;
    }
};