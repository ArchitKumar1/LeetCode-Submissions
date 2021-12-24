// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

class Solution {
public:
    bool safe(int n){
        while(n){
            int rem = n%10;
            if(rem == 0) return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2);
        for(int i = 1;i<n;i++){
            int a = i ;
            int b = n-i;
            if(safe(a)&& safe(b)){
                ans[0] = a;
                ans[1] = b;
                return ans;
            }
        }
        return ans;
    }
};