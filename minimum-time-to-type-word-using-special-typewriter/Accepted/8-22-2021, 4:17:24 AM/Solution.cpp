// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        char back = 'a';
        for(char s : word){
            ans += 1 + min((back-s+ 26)%26,(s-back + 26)%26);
            back = s;
        }
        return ans;
    }
};