// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int totalMoney(int n) {
        
        int base = 0;
        int pos = 0;
        vector<int> week(7);
        iota(week.begin(),week.end(),1);
        int ans = 0;
        while(n--){
            ans +=  base+week[pos];
            pos = pos + 1;
            if(pos == 7){
                pos = 0;
                base += 1;
            }
        }
        return ans;
    }
};