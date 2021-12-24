// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

class Solution {
public:
    int uniqueLetterString(string s) {
        
        int MOD = 1e9+7;
        long long int ans = 0;
        
        vector<vector<int>> cnt(26);
        
        int n = s.size();
        for(int i = 0;i<n;i++){
            cnt[s[i]-'A'].push_back(i);
        }
        
        for(int i= 0;i<26;i++){
            for(int j = 0;j<cnt[i].size();j++){
                long long int L = (j==0 ? cnt[i][j] : cnt[i][j] - cnt[j][j-1]);
                long long int R = (j+1 == cnt[i].size() ?  n-1 - cnt[i][j] : cnt[i][j+1]-cnt[i][j]);
                L++,R++;
                (ans += (L*R) %MOD)%= MOD;
            }
        }
        return ans;
    }
};