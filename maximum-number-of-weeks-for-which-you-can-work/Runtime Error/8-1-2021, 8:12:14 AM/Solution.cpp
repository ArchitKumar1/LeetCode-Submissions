// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work

class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        int maxi = *max_element(m.begin(),m.end());
        int sum = 0;
        int ans = 0;
        for(int c : m) sum += c;
        if( maxi > (sum - maxi)){
            ans += 2*(sum-maxi) + 1;
        }else{
            ans = sum;
        }
        return ans;
    }
};