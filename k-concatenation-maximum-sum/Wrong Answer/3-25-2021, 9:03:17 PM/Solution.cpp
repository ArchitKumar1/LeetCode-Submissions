// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int s = 0;
        for(int x : arr){
            s += x;
        }
        int p = 0;
        int c = 0;
        for(int x : arr){
            c +=x;
            p = max(p,c);
        }
        reverse(arr.begin(),arr.end());
        c = 0;
        int su = 0;
        for(int x : arr){
            c +=x;
            su = max(su,c);
        }
        int a1 = 0;
        int a2 = k*s;
        int a3 =  (k>1) ? p +su : 0;
        int a4 = (k>2) ? p + su + (k-2)*s : 0;
        
        return max({a1,a2,a3,a4});
    }
};