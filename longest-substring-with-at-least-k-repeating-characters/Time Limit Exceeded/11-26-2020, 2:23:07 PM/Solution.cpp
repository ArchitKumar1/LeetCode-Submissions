// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int ans = 0;
        int n = s.size();
        for(int U = 1;U<=26;U++){
            vector<int> cnt(40,0);
            
            set<int> uniq;
            int ltk = 0;
            
            for(int i = 0,j=0;i<n;i++){
                uniq.insert(s[i]-'a');
                cnt[s[i]-'a']++;
                if(cnt[s[j]-'a'] == k){
                    ltk--;
                }
                if(cnt[s[j]-'a'] == 1){
                    ltk++;
                }
                while(uniq.size() > U){
                    cnt[s[j]-'a']--;
                    if(cnt[s[j]-'a'] == 0){
                        uniq.erase(s[j]-'a');
                        ltk--;
                    }
                    if(cnt[s[j]-'a'] == (k-1)){
                        ltk++;
                    }
                    
                }
                if(ltk ==0){
                    ans = max(ans,i-j+1);
                }
            }
        }
        return ans;
                   
    }
};