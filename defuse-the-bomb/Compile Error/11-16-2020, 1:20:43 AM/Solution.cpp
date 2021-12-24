// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(n);
        int n = code.size();
        
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