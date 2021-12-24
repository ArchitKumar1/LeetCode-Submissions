// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int currsum = 0;
        int n =arr.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            currsum += arr[i];

            if(i>=k){
                double temp = 1.0*currsum/k;
                ans += temp>=t;
                currsum -= arr[i-k];
                
            }
            
        }
        return ans;
    }
};