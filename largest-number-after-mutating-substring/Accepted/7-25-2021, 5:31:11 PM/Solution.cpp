// https://leetcode.com/problems/largest-number-after-mutating-substring

class Solution {
public:
    string maximumNumber(string s, vector<int>& v) {
        int n = s.size();
        string t;
        bool done = 0;
        for(int i = 0;i < n;i++ ){
            int d = s[i] -'0';
            if( v[d] > d){
                if(done == 0){
                    done = 1;
                    t += '0' + v[d];
                    while((i+1) < n && v[s[i+1]-'0'] >= (s[i+1]-'0')){
                        cout << i+1 << endl;
                        t += '0' + v[s[i+1]-'0'];
                        i++;
                    }
                }else{
                    t += '0' + d;
                }
                
            }else{
                t += '0' + d;
            }
        }
        cout << endl;
        return t;
    }
};