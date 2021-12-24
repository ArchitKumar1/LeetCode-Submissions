// https://leetcode.com/problems/count-number-of-homogenous-substrings

class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int MOD = 1e9+7;
        int n = s.size();
        for(int i =0;i<n;i++){
            int cnt = 1 ;
            while(i+1 < n && s[i+1] == s[i]){
                cnt++,i++;
            }
            (ans += (1LL*cnt*(cnt+1)/2)%MOD)%=MOD;
        }
        return ans;
    }
};