// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int N) {
        int fib[N+1];
        fib[0] = 0;
        fib[1] = 1;
        for(int i = 2;i<=N;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[N];
    }
};