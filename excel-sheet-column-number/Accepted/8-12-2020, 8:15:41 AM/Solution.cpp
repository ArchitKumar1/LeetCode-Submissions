// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        reverse(s.begin(),s.end());
        for(int i = 0;i<s.size();i++){
            ans += (s[i] - 'A'+1)*pow(26,i);
        }
        return ans;
        
    }
};