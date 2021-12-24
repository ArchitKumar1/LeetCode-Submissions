// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k

class Solution {
    #define LL long long int 
public:
    int findMinFibonacciNumbers(int k) {
        vector<LL> all = {1,1};
        
        LL a  = 1,b = 1,c;
        while(c < 1.1e9 ){
            c = a+b;
            a = b;
            b = c;
            all.push_back(c);
        }
        int ans = 0;
        reverse(all.begin(),all.end());
        
        for(int c : all){
            if(k == 0) break;
            if(k-c >=0){
                ++ans;
                k-=c;
            }
        }
        return ans;
        
    }
};