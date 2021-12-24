// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> cnts(26,0);
        for(char c : s){
            cnts[c-'a']++;
        }
        set<pair<int,int>> ss;
        map<int,int> m1;
        for(int i = 0;i<26;i++){
            if(cnts[i] > 0){
                ss.insert({cnts[i],i});
                m1[cnts[i]]++;
            }
        }
        
        int ans = 0;
        for(auto [cnt,i]: ss){
            int beg = cnt;
            while(cnt>0 && m1[cnt] >1){
                cnt--;
                ans++;
            }
            m1[beg]--;
            m1[cnt]++;
        }
        return ans;
        
    }
};