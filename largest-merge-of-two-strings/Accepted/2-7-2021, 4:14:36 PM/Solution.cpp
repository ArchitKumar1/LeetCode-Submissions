// https://leetcode.com/problems/largest-merge-of-two-strings

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int n = word1.size();
        int m = word2.size();
        int i=0,j=0;
        
        while(i < n || j < m){
            if(j == m){
                ans += word1[i++];
            }else if(i == n){
                ans += word2[j++];
            }else{
                if(word1.substr(i) > word2.substr(j)){
                    ans += word1[i++];
                }else{
                    ans += word2[j++];
                }
            }
        }
        return ans;
    
    }
};