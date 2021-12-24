// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers

class Solution {
    #define LL long long int 
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans= 0;
        map<long long int ,int> m1,m2;
        for(int c : nums1)m1[(LL)c*c]++;
        for(int c : nums2)m2[(LL)c*c]++;
        
        int n = nums1.size();int m = nums2.size();
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                LL  prod = 1LL * nums1[i]*nums1[j];
                ans += m2[prod]>= 1;
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = i+1;j<m;j++){
                LL  prod = 1LL * nums2[i]*nums2[j];
                ans += m1[prod]>= 1;
            }
        }
        return ans;
    }
};