// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work

class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long maxi = *max_element(m.begin(),m.end());
        long long sum = 0;
        long long ans = 0;
        for(int c : m) sum += c;
        if( maxi > (sum - maxi)){
            ans += 2*(sum-maxi) + 1;
        }else{
            ans = sum;
        }
        return ans;
    }
};