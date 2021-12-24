// https://leetcode.com/problems/longest-chunked-palindrome-decomposition

class Solution {
public:
    int longestDecomposition(string text) {
        
        int n = text.size();
        string front,back;
        
        int ans = 0;
        int i = 0,j=n-1;
        while (i < j){
            front += text[i];
            back = text[j] + back;
            
            if(front == back){
                if (i > j) ans+=2;
                else ans += 1;
                front = back="";
            }
            i++,j--;
        }
        return ans + 1;
    }
};