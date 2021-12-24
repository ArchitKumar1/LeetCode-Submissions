// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

class Solution {
public:
    int uniqueLetterString(string s) {
        
        int MOD = 1e9+7;
        int ans = 0;
        int N = s.size();
        for(int i = 0;i<N;i++){
            unordered_set<int> cand;
            unordered_map<int,int> m1;
            for(int j = i;j<N;j++){
                if(m1[s[j]] == 1){
                    cand.erase(cand.find(s[j]));
                }
                if(m1[s[j]] == 0){
                    cand.insert(s[j]);
                }
                m1[s[j]]++;
                ans += cand.size();
                ans %= MOD;
            }
        }
        return ans;
    }
};