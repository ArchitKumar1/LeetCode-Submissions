// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> m1;
        int s = 0;
        for(int c : nums){
            m1[c]++;
        }
        for(int c : nums){
            s += c * (m1[c]==1);
        }
        return s;
    }
};