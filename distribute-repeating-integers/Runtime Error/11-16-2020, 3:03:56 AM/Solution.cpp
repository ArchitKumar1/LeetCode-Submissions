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
            cout << i << endl;
            if(i == n)return true;
            int q = quantity[i];
            bool ans = 0;
            for(int i = 0;i<m;i++){
                if(availaible[i] >= q){
                    availaible[i] -= q;
                    ans |= solve(i+1);
                    availaible[i] += q;
                }
            }
            return ans;
        };
        
        return solve(0);
        
    }
};