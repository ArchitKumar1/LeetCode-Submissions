// https://leetcode.com/problems/reformat-phone-number

class Solution {
public:
    string reformatNumber(string number) {
        int n = number.size();
        string s ;
        for(char c : number){
            if(c>='1' && c<='9'){
                s += c;
            }
        }
        string fans;
        int m = s.size();
        for(int i = 0;i<m;i++){
            fans += s[i];
            
            if(i%3 == 2){
                fans += '-';
            }
            if(m-i == 4){
                fans += s.substr(i,2) + '-' + s.substr(i+2,2);
                break;
            }
        }
        return fans;
        
    }
};