// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int count = 0;
        
        int n =arr.size();
        int i = 0,j=0;
        int sum =0;
        int ans =0 ;
        while( j< n){
            if(count < k){
                sum += arr[j];
                count++;
                j++;
            }else{
                sum-=arr[i];
                count--;

                i++;
            }
            if(count == k  && sum/k >= t) ans++;
        }
        return ans;
    }
};