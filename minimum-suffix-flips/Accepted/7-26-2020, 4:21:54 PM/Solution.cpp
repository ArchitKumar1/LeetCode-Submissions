// https://leetcode.com/problems/minimum-suffix-flips

class Solution {
public:
    int minFlips(string target) {
        int curr = 0;
        int ans = 0;
        for(char x : target){
            int X = x-'0';
            if(X^curr){
                ans+=1;
                curr^=1;
            }
        }
        return ans;
    }
};