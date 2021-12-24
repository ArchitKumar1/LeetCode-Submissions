// https://leetcode.com/problems/distribute-repeating-integers

class Solution {
public:
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        
        map<int,int> m1;
        vector<int> availaible;
        for(int c : nums)m1[c]++;
        for(auto x : m1){
            availaible.push_back(x.second);
        }
        int n = quantity.size();
        int m = availaible.size();
        
        function<bool(int i)> solve = [&](int i){
            if(i == n)return true;
            int q = quantity[i];
            bool ans = 0;
            for(int j = 0;j<m;j++){
                if(availaible[j] >= q){
                    availaible[j] -= q;
                    ans |= solve(i+1);
                    availaible[j] += q;
                }
            }
            return ans;
        };
        
        return solve(0);
        
    }
};