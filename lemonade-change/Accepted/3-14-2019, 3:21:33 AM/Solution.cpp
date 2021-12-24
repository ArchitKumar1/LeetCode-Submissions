// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0,tw=0;
        int ans = 1;
        for(int c : bills){
            if(c == 5){
                f++;
            }else if(c == 10){
                t++;
                if(f>0){
                    f--;
                }else{
                    ans = 0;
                    break;
                }
            }else{
                tw++;
                if(t>0 && f>0){
                    t--; f--;
                }else if(f>3){
                    f = f-3;
                }else{
                    ans = 0;
                    break;
                }
            }
        }
        return ans;
    }
};