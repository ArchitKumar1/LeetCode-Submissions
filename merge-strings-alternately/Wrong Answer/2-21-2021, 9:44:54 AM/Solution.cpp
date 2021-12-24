// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        
        int i = 0,j = 0;
        int p = 1;
        int n =  word1.size();
        int m =  word2.size();
        while(i < n || j < m){
            if(i == n) ans += word1[i++];
            else if(j == m) ans += word2[j++];
            else{
                if(p){
                    ans += word1[i++];
                }else{
                    ans += word2[j++];
                }
                p^=1;
            }
        }
        return ans;
    }
};