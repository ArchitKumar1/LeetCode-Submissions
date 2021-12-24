// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                if(i == 0){
                    if(i+1 == '?'){
                        s[i] == 'a';
                    }else{
                        for(int i = 0;i<26;i++){
                            if(s[i+1]!=('a' + i)){
                                s[i] = ('a'+i);
                                i = 100;
                            }
                        }
                    }
                }else if(i == n-1){
                    s[i] = ('a' + (s[i-1]- 'a' + 1)%26);
                }else{
                    for(int i = 0;i<26;i++){
                        if(s[i+1] == '?'){
                            if(s[i-1]!=('a' +i)){
                                s[i] = ('a'+i);
                                i = 100;
                            }
                        }else{
                            if(s[i-1]!=('a' + i) && s[i+1]!=('a' + i)){
                                s[i] = ('a'+i);
                                i = 100;
                            }
                        }
                    }
                }
            }
        }
        return s;
        
    }
};