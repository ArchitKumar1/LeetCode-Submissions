// https://leetcode.com/problems/number-of-ways-to-split-a-string

class Solution {
public:
    int numWays(string s) {
        int n = s.size();
        int n1 = count(s.begin(),s.end(),'1');
        cout << n1 << endl;
        int ans = 1;
        if(n1%3 || !n){
            return 0;
        }
        int cnt = n1/3;
 
        while(cnt){
            cnt -= *s.begin() == '1';
            s.erase(s.begin());
        }
        cout <<s << endl;
        cnt = n1/3;
        while(cnt){
            cnt -= s.back() == '1';
            s.pop_back();
        }
        cout <<s << endl;
        if(s.size()==0){
            return 0;
        }else{
            int a =0,b=0;
            while(*s.begin()=='0'){
                s.erase(s.begin());
                ++a;
            }
            while(s.back()=='0'){
                s.pop_back();
                ++b;
            }
            return (a+1)*(b+1);
        } 
        return 1;
    }
};