// https://leetcode.com/problems/reformat-the-string

class Solution {
public:
    string reformat(string s) {
        int x=0,y=0;
        string a,b;
        for(char c : s){
            if( c>='0' && c<='9'){
                x +=1;
                a += c;
            }else{
                y +=1;
                b += c;
            }
        }
        if(abs(x-y)>1){
            return "";
        }
        string ans = "";
        if(x < y) swap(x,y);
        for(int i= 0;i<y;i++){
            ans += a[i];
            ans += b[i];
        }
        if(x != y) ans += a[a.size()-1];
        return ans;
    }
};