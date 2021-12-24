// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> cnt[26];
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            cnt[c-'a'].push_back(i);
        }
        int ans = 0;
        for(auto c : cnt){
            for(int x : c){
                int en = c[c.size()-1];
                int st = c.front();
                if(c.size() >= k){
                    ans = max(ans,en-st+1);
                }
            }
        }
        return ans;
    }
};