// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        map<int,int> m1;
        for(int c : nums){
            m1[c]++;
        }
        int ans =0 ;
        for(auto x : m1){
            auto [v,c1] = x;
            if(2*v == k){
                ans += c1/2;
                continue;
            }
            int c2 = m1[k-v];
            if(c2 > 0){
                m1[k-v] -= min(c1,c2);
                m1[v] -= min(c1,c2);
                ans += min(c1,c2);
            }
            
        }
        return ans;
    }
};