// https://leetcode.com/problems/finding-3-digit-even-numbers

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> m1;
        vector<int> ans;
        
        int n = digits.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++){
                    if(i==j || j==k || k==i) continue;
                    if(digits[i] == 0) continue;
                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(m1[x] || x%2 == 1) continue;
                    ans.push_back(x);
                    m1[x] = 1;
                    
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};