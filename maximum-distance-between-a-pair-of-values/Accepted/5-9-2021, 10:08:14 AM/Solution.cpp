// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0,j = 0;i < n;i++){
            while(j+1 < m && nums2[j+1] >= nums1[i]){
                j++;
            }
            if(j < m && nums2[j] >= nums1[i] && j>=i){
                ans = max(ans,j-i);
            }
        }
        return ans;
    }
};