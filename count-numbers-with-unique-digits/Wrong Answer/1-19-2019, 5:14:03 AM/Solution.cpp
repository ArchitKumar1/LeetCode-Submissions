// https://leetcode.com/problems/count-numbers-with-unique-digits

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        int total=pow(10,n);
        int cnt=1;
        for(int i=0;i<n;i++)
            cnt*=(10-i);
        return (cnt+1);
    }
};