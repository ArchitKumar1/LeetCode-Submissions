// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating

class Solution {
public:
    int minSwaps(string s) {
        int ones = count(s.begin(),s.end(),'1');
        int zeros = count(s.begin(),s.end(),'0');
        int n = s.size();
        
        auto getcnt = [&](int st){
            int a = 0,b = 0;
            for(int i = 0; i < n;i++,st^=1){
                if(s[i]-'0' != st){
                    if(st) a++;
                    else b++;
                }
            }
            if(a == b) return a;
            else return INT_MAX;
            
        };
        int st = 0;
        int ans;
        if(ones != zeros){
            st = ones > zeros;
            ans = getcnt(0);
        }else{
            int ans1 = getcnt(0);
            int ans2 = getcnt(1);
            
            ans = min(ans1,ans2);
            
        }
        return ans == INT_MAX ? -1 : ans;

    }
};