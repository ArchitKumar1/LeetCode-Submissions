// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m1;
        for(int c : nums) m1[c]++;
        
        vector<pair<int,int>> v(m1.begin(),m1.end());
        sort(v.rbegin(),v.rend());
        int fans = 0;
        int ans = 0;
        int mini = *min_element(nums.begin(),nums.end());
        
        for(auto x : v){
            if(x.first == mini) continue;
            ans += x.second;
            fans += ans;
        }
        return fans;
    }
};