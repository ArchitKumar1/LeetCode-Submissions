// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        set<int> s;
        for(int c : arr) s.insert(c);
        
        int n = arr.size() - 1;
        return min((int)arr.size(),*s.rbegin());
    }
};