// https://leetcode.com/problems/maximum-value-after-insertion

class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0] == '-'){
            int pos = 0;
            bool done = 0;
            for(char c : n){
                if(c == '-'){
                    pos++;
                    continue;
                }
                int v = (c - '0');
                if(v < x){
                    n.insert(n.begin()+pos,(char)(x+'0'));
                    done = 1;
                    break;
                }
                pos++;
            }
            if(!done) n.push_back((char)(x+'0'));
            return n;
        }else{
            int pos = 0;
            bool done = 0;
            for(char c : n){
                if(c == '-') continue;
                int v = (c - '0');
                if(v > x){
                   n.insert(n.begin()+pos,(char)(x+'0'));
                    done = 1;
                    break;
                }
                pos++;
            }
            if(!done) n.push_back((char)(x+'0'));
            return n;
        }
        
    }
};