// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int N = 2*n;
        
        int M = 1 << N;
        vector<string> fans;
        for(int i =0;i<M;i++){
            int sum = 0;
            int safe =1;
            for(int j  = 0;j<N;j++){
                int bit = i>>j&1;
                if(bit) sum -= 1;
                else sum += 1;
                if(sum < 0) safe = 0;
            } 
            if(sum!=0) safe = 0;
            if(!safe) continue;
            string ans;
            for(int j  = 0;j<N;j++){
                int bit = i>>j&1;
                if(bit) ans += ')';
                else ans += '(';
            }
            fans.push_back(ans);
        }
        return fans;
    }
    
};