// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    bool v(char x){
        string s ="aeiou";
        for(char c : s){
            if(x == c){
                return 1;
            }
        }
        return 0;
    }
    int maxVowels(string s, int k) {
        
        int fans = 0;
        int ans =0 ;
        int n = s.size();
        int j = 0;
        for(int i =0;i<n;i++){
            ans += v(s[j]);
            while(i-j+1>k){
                if(v(s[j]))ans--;
                j++;
            }
            fans = max(fans,ans);
            
        }
        return fans;
    }
};