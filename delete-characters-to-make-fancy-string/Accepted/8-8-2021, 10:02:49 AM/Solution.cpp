// https://leetcode.com/problems/delete-characters-to-make-fancy-string

class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int n = s.size();
        for(int i =0;i < n;i++){
            int cnt = 1;
            char base = s[i];
            while(i+1<n && s[i+1] == base){
                cnt++,i++;
            }
            ans += string(min(2,cnt),base);
        }
        return ans;
    }
};