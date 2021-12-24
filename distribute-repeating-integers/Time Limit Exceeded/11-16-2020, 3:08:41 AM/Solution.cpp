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
        
        sort(availaible.begin(),availaible.end());
        function<bool(int i)> solve = [&](int i){
            if(i == n)return true;
            int q = quantity[i];
            for(int j = 0;j<m;j++){
                if(availaible[j] >= q){
                    availaible[j] -= q;
                    if(solve(i+1)) return true;
                    availaible[j] += q;
                }
            }
            return false;
        };
        
        return solve(0);
        
    }
};