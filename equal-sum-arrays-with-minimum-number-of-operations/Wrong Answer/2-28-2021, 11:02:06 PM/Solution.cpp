// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> pq1;
        priority_queue<int,vector<int> ,greater<int>> pq2;
        int s1 = 0,s2 = 0;
        for(int c : nums1) s1+=c;
        for(int c : nums2) s2+=c;
        if(s1 < s2){
            swap(s1,s2);
            swap(nums1,nums2);
        }
        for(int c : nums1) pq1.push(c-1); 
        for(int c : nums2) pq1.push(6-c); 
        
        int diff = s1 - s2;
        int ans = 0;
        
        while(diff > 0 && pq1.size()){
            int f1 = pq1.top();
            diff -= f1;
            pq1.pop();
            ans++;
        }
        return ans;
    }
};