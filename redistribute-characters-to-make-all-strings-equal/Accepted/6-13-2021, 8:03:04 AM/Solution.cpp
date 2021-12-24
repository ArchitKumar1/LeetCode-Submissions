// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26,0);
        int n= words.size();
        for(string s : words) for(char c : s)cnt[c-'a']++;
        bool ans = 1;
        for(int c : cnt){
            if(c%n > 0){
                ans = 0;
            }
        }
        return ans;
    }
};