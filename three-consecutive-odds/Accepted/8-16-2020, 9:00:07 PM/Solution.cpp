// https://leetcode.com/problems/three-consecutive-odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
         
        int n = arr.size();
        bool ok = 0;
        for(int i = 0;i+2<n;i++){
            ok|=(arr[i]&1 && arr[i+1]&1 && arr[i+2]&1);
        }
        return ok;
    }
};