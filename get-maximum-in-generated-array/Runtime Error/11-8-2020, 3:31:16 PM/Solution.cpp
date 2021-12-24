// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        int arr[n+1];
        arr[0] = 0,arr[1] = 1;
        for(int i = 1;i<=n;i++){
            int x = 2*i;
            if(x <= n){
                arr[x] = arr[i];
            }
            if(x+1<=n){
                arr[x+1] = arr[i] + arr[i+1];
            }
        }
        return *max_element(arr,arr+n+1);
    }
};