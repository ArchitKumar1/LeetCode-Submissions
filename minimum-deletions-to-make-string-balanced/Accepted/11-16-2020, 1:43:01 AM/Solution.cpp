// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> suff1(n+2),suff2(n+2);
        
        int ca = 0,cb = 0;
        
        for(int i = n-1;i>=0;i--){
            if(s[i] == 'a') suff1[i]++;
            if(s[i] == 'b') suff2[i]++;
            suff1[i] += suff1[i+1];
            suff2[i] += suff2[i+1];

        }
        int ans = INT_MAX;
        
        for(int i =0;i<n;i++){
            ans = min(ans,cb + suff1[i+1]);
            if(s[i] == 'a') ca++;
            else cb++;
        }
        return ans;
    }
};