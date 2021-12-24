// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) {
        int z=0,o=0;
        for(int i=0;i<s.size();i++){
            int cnt=1;
            while(i+1<s.size()&& s[i+1]==s[i]){
                cnt++,i++;
            }
            if(s[i]=='0')z=max(z,cnt);
            else o=max(o,cnt);
        }
        return o > z;
    }
};