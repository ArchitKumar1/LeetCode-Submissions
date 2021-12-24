// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int s = 0;
        accumulate(arr.begin(),arr.end(),s);
        
        int p = 0;
        int c = 0;
        for(int x : arr){
            c +=x;
            p = max(p,c);
        }
        reverse(arr.begin(),arr.end());
        c = 0;
        for(int x : arr){
            c +=x;
            s = max(s,c);
        }
        return max(s,0) + max(p,0) + max(0,(max(0,k-2))*s);
    }
};