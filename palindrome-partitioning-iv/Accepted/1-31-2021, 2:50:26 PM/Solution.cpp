// https://leetcode.com/problems/palindrome-partitioning-iv

class Solution {
public:
    bool checkPartitioning(string s) {
        
        int n = s.size();
        int pali[n][n];
        memset(pali,0,sizeof(pali));
        
        for(int l = 0;l<n;l++){
            for(int i = 0;i+l<n;i++){
                int j = i+l;
                if(i == j) pali[i][j] = 1;
                else if(i+1 == j) pali[i][j] = (s[i] == s[j]);
                else pali[i][j] = (s[i] == s[j] && pali[i+1][j-1]);
            }
        }
        bool ans = 0;   
        for(int i = 0;i<n;i++){
            for(int j = i+2;j<n;j++){
                ans |= pali[0][i] && pali[i+1][j-1] && pali[j][n-1];
            }
        } 
        return ans;
    }
};