// https://leetcode.com/problems/perform-string-shifts

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sh = 0;
        for(auto x : shift){
            if(x[0] == 0){
                sh -= x[1];
            }else{
                sh += x[1];
            }
        }
        cout<< sh << endl;
        if(sh < 0){
            while(sh--){
                s += s[0];
                s.erase(s.begin());
            }
        }
        if(sh > 0){
            while(sh--){
                s =  *s.rbegin() + s;
                s.erase(s.begin()+s.size()-1);
            }
        }
        return s;
    }
};