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
            while(res.size() && *res.begin() > c && cnt[*res.begin()-'a']){
                vis[*res.begin()-'a'] = 0;
                res.erase(res.begin());
                
            }
            res += c;
            cout << res << endl;
            
            cnt[c-'a'] -= 1;  
        }
        return res;
        
    }
};