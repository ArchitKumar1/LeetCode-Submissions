// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        
        int ans = 0;
        
        for(int cnt = 0,i = 1;cnt < n/3;cnt++,i+=2){
            ans += piles[i];
        }
        return ans;
    }
};