// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words

class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        int x = 0;
        for(char c : f){
            x*=10;
            x += (c -'a');
        }
        int y = 0;
        for(char c : s){
            y*=10;
            y += (c -'a');
        }
        int z = 0;
        for(char c : t){
            z*=10;
            z += (c -'a');
        }
        return ((x+y)==z);
        
    }
};