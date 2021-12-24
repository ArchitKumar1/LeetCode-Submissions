// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        bool ok = 1;
        for(int i=1;i<arr.size();i++){
            ok&= (arr[i]- arr[i-1] == arr[1] - arr[0]);
        }
        return ok;
    }
};