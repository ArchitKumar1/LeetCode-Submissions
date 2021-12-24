// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

class Solution {
public:
    string smallestSubsequence(string text) {
    
        vector<int> cnt(26,0);
        vector<int> vis(26,0);
        
        for(char c  : text){
            cnt[c-'a']++;
        }
        string res = "";
        for(char c : text){
            if(vis[c-'a'] == 1) continue;
            vis[c-'a'] = 1;
            while(res.size() && res.back() > c && cnt[res.back()-'a']){
                vis[res.back()-'a'] = 0;
                res.pop_back();
                
            }
            res += c;
            cout << res << endl;
            
            cnt[c-'a'] -= 1;  
        }
        return res;
        
    }
};