// https://leetcode.com/problems/number-of-substrings-with-only-1s

class Solution {
public:
    int numSub(string s) {
        long long int cnt = 0;
        int ans =0 ;
        for(char c : s){
            if(c == '1') {
                cnt += 1;
            }else{
                ans += cnt*(cnt+1)/2;
                cnt = 0;
            }
        }
        ans += cnt*(cnt+1)/2;
        return ans%(1e9+7);
        
    }
};