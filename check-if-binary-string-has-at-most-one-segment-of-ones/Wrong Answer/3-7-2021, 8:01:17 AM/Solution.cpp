// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n= s.size();
        bool ans = 0;
        for(int i=0;i+1<n;i++){
            ans|=(s[i] =='1') && s[i+1] =='1';
        }
        return ans;
    }
};