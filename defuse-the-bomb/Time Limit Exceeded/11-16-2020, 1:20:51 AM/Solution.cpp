// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int> ans(n);
        
        for(int i = 0;i<n;i++){
            
            if(k > 0){
                int K = k;
                int j =(i+1)%n;
                while(K--){
                    ans[i] += code[j];
                    j =(j+1)%n;
                }
            }else if(k < 0){
                int K = k;
                int j =(i-1+n)%n;
                while(K--){
                    ans[i] += code[j];
                    j =(j-1+n)%n;
                }
            }else{
                ans[i] = 0;
            }
        }
        return ans;
    }
};