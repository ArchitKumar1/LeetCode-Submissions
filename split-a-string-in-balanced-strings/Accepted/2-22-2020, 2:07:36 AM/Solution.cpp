// https://leetcode.com/problems/split-a-string-in-balanced-strings

class Solution {
public:
    int balancedStringSplit(string s) {
        map<int,int>m1;
        int curr= 0 ;
        int ans = 0;
        for(char c : s){
            curr += c == 'L';
            curr -= c == 'R';
            if(curr == 0){
                ans+= 1;
            }
        }
        return ans;
    }
};