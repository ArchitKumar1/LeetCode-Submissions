// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int n) {
        int q = n/26;
        string ans(q,'Z');
        ans += ('A' + n%26 - 1);
        return ans;
    }
};