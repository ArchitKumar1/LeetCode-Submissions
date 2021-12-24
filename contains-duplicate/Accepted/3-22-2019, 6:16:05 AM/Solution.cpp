// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m1;
        for(auto num : nums){
            m1[num]++;
        }
        for(auto x : m1){
            if(x.second>1){
                return 1;
            }
        }
        return 0;
    }
};