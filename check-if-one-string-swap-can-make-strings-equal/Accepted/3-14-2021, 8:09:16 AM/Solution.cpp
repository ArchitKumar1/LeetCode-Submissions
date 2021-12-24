// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                string t = s1;
                swap(t[i],t[j]);
                if(t == s2) return 1;
            }
        }
        if(s1 == s2) return 1;
        return 0;
    }
};