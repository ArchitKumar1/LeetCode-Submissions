// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int m[128]={0};
        char ans;
        for(auto c: s)
            m[c]++;
        for(auto c: t)
            m[c]--;
        for(int i=0;i<128;i++){
            if(m[i] == -1){
                ans = i;
            }
        }
        
        return ans;
    }
};