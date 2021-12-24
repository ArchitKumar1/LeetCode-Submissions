// https://leetcode.com/problems/minimum-moves-to-convert-string

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        s += "OO";
        int cnt = 0;
        for(int i = 0;i+2 < n;i++){
            if(s[i] == 'X' || s[i+1] == 'X' || s[i+2] == 'X'){
                s[i] = 'O';
                 s[i+1] = 'O';
                 s[i+2] = 'O';
                cnt += 1;
            }
        }
        return cnt;
        
    }
};