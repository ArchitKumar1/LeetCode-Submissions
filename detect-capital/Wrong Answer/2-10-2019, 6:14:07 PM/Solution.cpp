// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]>=97){
            for(int i=1;i<word.length();i++){
                if(word[i]<97) return false;
            }
            return true;
        }
        else{
            if(word[1]<97){
                for(int i=2;i<word.length();i++){
                    if(word[i]>97) return false;
                }
                return true;
            }
            else{
                for(int i=2;i<word.length();i++){
                    if(word[i]<97) return false;
                }
                return true;
            }
            
        }
    }
};