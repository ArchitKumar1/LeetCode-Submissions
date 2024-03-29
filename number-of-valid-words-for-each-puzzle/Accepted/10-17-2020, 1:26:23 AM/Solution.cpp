// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle

class Solution {
public:
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        const int N = 26;
        int n = words.size();
        int m = puzzles.size();
        
        auto getmask = [&](string s){
            int ans = 0;
            for(char c : s){
                ans |= (1 << (c-'a'));
            }
            return ans;
        };
        vector<int> cnt(1 << N,0);
        for(string s : words){ 
            cnt[getmask(s)]++;
        }
        vector<int> fans(m,0);
        for(int i = 0;i<m;i++){
            int ans = 0;
            int mask = getmask(puzzles[i]) ;
            for(int s = mask;s > 0;s=(s-1)&mask){
                int first=  (1 << (puzzles[i][0] - 'a'));
                if( (s & first) > 0)
                    ans += cnt[s];
            }
            fans[i] = ans;
        }
        return fans;
        
    }
};