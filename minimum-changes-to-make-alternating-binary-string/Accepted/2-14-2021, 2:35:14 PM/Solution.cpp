// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = "01";
        int a = 0;
        for(int i = 0;i<n;i++){
            a += s[i] == t[i%2];
        }
        return min(a,n-a);
    }
};