// https://leetcode.com/problems/perform-string-shifts

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sh = 0;
        int n = s.size();
        for(auto x : shift){
            if(x[0] == 0){
                sh -= x[1];
            }else{
                sh += x[1];
            }
        }
        rotate(s.begin(),s.begin()+ (n-sh%n)%n,s.end());
        return s;
    }
};