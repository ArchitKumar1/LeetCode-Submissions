// https://leetcode.com/problems/decode-xored-permutation

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        
        
//         1  2  3  4  5 
            
//         12 23 34 45 51
        
        
        int n = encoded.size();
        
        int N = n+1;
        
        int all = 0;
        for(int i = 1;i<=N;i++) all^= i;
        
        for(int i = 0;i<n;i+=2) all^=encoded[i];
        
        vector<int> ans(N);
        ans[N-1] = all;
        
        for(int i = N-2;~i;i--){
            ans[i] = encoded[i]  ^ ans[i+1];
        }
        return ans;
    }
};