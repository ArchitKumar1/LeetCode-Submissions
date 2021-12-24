// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto c : nums){
            a = a^c;
        }
        return a;
    }
};