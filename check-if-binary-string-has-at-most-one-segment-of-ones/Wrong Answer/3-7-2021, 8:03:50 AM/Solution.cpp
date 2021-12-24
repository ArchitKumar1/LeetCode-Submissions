// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n= s.size();
        vector<int> ans;
        
        int prev = 0;
        for(int i=1;i<n;i++){
            if(s[i] == '1') if(i!= prev+1)return 0;
        }
        return 1;
    }
};