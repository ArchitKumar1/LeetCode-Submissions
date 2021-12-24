// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        
        auto s = [&](vector<int> v){
            vector<int> y = v;
            sort(y.begin(),y.end());
            return y == v;
        };
        
        int N = 120;
        bool ans = 0;
        while(N--){
            int x = *nums.begin();
            nums.erase(nums.begin());
            nums.push_back(x);
            ans |= s(nums);
        }
        return ans;
    }
};