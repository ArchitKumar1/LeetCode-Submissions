// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played

class Solution {
public:
    int numberOfRounds(string s, string f) {
        
        int h1 = stoi(s.substr(0,2));
        int h2 = stoi(f.substr(0,2));
        
        int m1 = stoi(s.substr(3,2));
        int m2 = stoi(f.substr(3,2));

        int ans = 0;
        m2 = (60-m2)%60;
        if(h1 <= h2){
            ans = (h2-h1+1)*4 - ( (m1/15)  + (m1%15 != 0)) -  ( (m2/15)  + (m2%15 != 0));
        }
        else{
             h2%=24;
            
            ans = ans = (h2+h1+1)*4 - ( (m1/15)  + (m1%15 != 0)) -  ( (m2/15)  + (m2%15 != 0));
        }
        return ans;
    }
};