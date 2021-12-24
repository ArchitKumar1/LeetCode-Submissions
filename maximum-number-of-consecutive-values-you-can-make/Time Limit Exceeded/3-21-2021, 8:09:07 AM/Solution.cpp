// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        const int N = 4e6+1;
        bitset<N> b;
        
        b[0] = 1;
        for(int c : coins){
             b |= b<<c;
        }
        
        int ans = 0 ;
        
        for(int i = 0;i<N;i++){
            if(b[i] == 0) continue;
            int c = 1;
            while( b[i+1] == 1){
                c++;
                i++;
            }
            ans = max(ans,c);
        }
        return ans;
    }
};