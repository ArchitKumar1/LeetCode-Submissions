// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int ans = 0;
        for(int i = 0;i < prices.size();i++){
            int cnt = 1;
            while(i+1<prices.size() && prices[i+1]+1 == prices[i]){
                cnt++;
                i++;
            }
            ans += 1LL* cnt * (cnt+1)/2;
        }
        return ans;
    }
};