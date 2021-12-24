// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        set<int> s;
        for(int i =1;i<arr.size();i++){
            s.insert(arr[i]-arr[i-1]);
        }
        return s.size()==1;
        
        
    }
};