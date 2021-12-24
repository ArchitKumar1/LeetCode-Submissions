// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        set<int> s;
        for(int c : arr) s.insert(c);
        
        return s.size();
    }
};