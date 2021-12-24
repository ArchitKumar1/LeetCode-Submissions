// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string

class Solution {
public:
    int uniqueLetterString(string s) {
        
        int MOD = 1e9+7;
        int ans = 0;
        int N = s.size();
        for(int i = 0;i<N;i++){
            set<int> se;
            for(int j = i;j<N;j++){
                se.insert(s[j]);
                ans += se.size();
                cout << "SE" << se.size() << " ";
                ans %= MOD;
            }
            cout << endl << ans << endl;
        }
        return ans;
    }
};