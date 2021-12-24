// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> a;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1)a.push_back(i);
        }
        bool ok = 1;
        for(int i = 0;i+1<a.size();i++ ){
            ok&= (a[i+1] - a[i]) >k;
        }
        return ok;
    }
};