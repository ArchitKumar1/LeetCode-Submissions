// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        int s = 0;
        for(int i = 0;i<n;i++){
            s += 2*i+1;
        }
        int avg = s/n;
        int ans = 0;
        for(int i = 0;i<n/2;i++){
            ans += (avg - (2*i + 1));
        }
        return ans;
    }
};