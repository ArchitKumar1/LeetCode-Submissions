// https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int maxDotProduct(vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        int n = v1.size();
        int m = v2.size();
        long long int  ans = 0;
        for(int i = 0;i<min(n,m);i++){
            if(v1[i] <0 && v2[i] <0) ans += v1[i] * v2[i];
        }
        for(int i = min(n,m)-1;~i;i--){
            if(v1[i] >=0 && v2[i] >= 0) ans += v1[i] * v2[i];
        }
        return ans;
    }
};