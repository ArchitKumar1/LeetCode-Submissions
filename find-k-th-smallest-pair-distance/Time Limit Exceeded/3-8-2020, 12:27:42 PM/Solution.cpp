// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> all;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                all.push_back(abs(nums[i]-nums[j]));
            }
        }
        sort(all.begin(),all.end());
        return all[k-1];
    }
};