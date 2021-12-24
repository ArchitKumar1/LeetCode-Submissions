// https://leetcode.com/problems/reformat-phone-number

class Solution {
public:
    string reformatNumber(string number) {
        int n = number.size();
        string s ;
        for(char c : number){
            if(c>='0' && c<='9'){
                s += c;
            }
        }
        string fans;
        int m = s.size();
        while(s.size() >0){
            if(s.size() > 4){
                fans += s.substr(0,3);
                fans += '-';
                s = s.substr(3);
            }else if(s.size() == 4){
                fans += s.substr(0,2);
                fans += '-';
                fans += s.substr(2,2);
                break;
            }else if(s.size() <= 3){
                fans += s;
                break;
            }
        }
        return fans;
        
    }
};