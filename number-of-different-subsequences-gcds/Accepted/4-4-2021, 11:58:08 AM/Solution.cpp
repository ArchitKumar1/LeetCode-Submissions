// https://leetcode.com/problems/number-of-different-subsequences-gcds

class Solution {
public:
    const int MAX = 2e5+1;
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<int> v(MAX);
        for(int c:nums){
            v[c] = 1;
        }
        
        int ans = 0;
        for(int i =1;i<MAX;i++){
            int g = 0;
            for(int j = i;j < MAX;j+=i){
                if(v[j]) g = __gcd(g,j);
            }
            if(g == i){
                ans += 1;
            }
        }
        return ans;
    }
};