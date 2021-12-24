// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        
        int val = 0;
        map<char,int> m1 = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        map<string,int> m2 = {{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
        
        
        int n = s.size();
        for(int i = 0;i<n;i++){
            bool f = 0;
            if(i +1<n){
                for(auto x : m2){
                    if(s.substr(i,2) == x.first){
                        val+= x.second;
                        f = 1;
                        i++;
                    }
                }
            }
            if(f) continue;
            for(auto x : m1){
                if(s[i] == x.first) val += x.second;
            }
        }
        
        return val;
    }
};