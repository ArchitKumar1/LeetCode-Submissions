// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m1;
        for(int c : arr){
            m1[c]+=1;
        }
        bool ok = 0;
        for(int c : arr){
            if(c == 0) ok|= m1[2*c]>=2;
            cout << c << " " << m1[2*c] << endl;
            ok|= m1[2*c]>=1;
        }
        return ok;
    }
};