// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters

class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int ans = 0;
        int n = s.size();
        for(int i = 0;i+2 < n;i++){
            string t = s.substr(i,3);
            if(t[0] != t[1] && t[1] != t[2] && t[2] != t[0]) ans++;
        }
        return ans;
    }
};