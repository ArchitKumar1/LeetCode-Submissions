// https://leetcode.com/problems/shuffle-string

class Solution {
public:
    string restoreString(string s, vector<int>& i) {
        int n = i.size();
        string ans(n,'a');
        for(int j =0;j<n;j++){
            ans[i[j]] = s[j];
        }
        return ans;
    }
};