// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> cnts(26,0);
        for(char c : s){
            cnts[c-'a']++;
        }
        map<int,int> m1;
        for(int c : cnts)m1[c]++;
        
        int ans = 0;
        for(int i = 0;i<26;i++){
            if(m1[cnts[i]] > 1){
                
                for(int j = cnts[i]-1,safe = 1;j>=0 && safe==1;j--){
                    ans += 1;
                    if(m1[j] == 0){
                        m1[j] += 1;
                        m1[cnts[i]] -=1;
                        cnts[i] = j;
                        safe = 0;
                    }
                }
            }
        }
        return ans;
        
    }
};