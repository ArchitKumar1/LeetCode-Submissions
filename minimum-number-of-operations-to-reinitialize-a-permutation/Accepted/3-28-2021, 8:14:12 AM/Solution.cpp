// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation

class Solution {
public:
    int reinitializePermutation(int n) {
        
        vector<int> arr(n);
        iota(arr.begin(),arr.end(),0);
        auto ogi = arr;
        int ans = 0;
        while(true){
            vector<int> narr(n);
            for(int i = 0;i<n;i++){
                if(i&1){
                    narr[i]= arr[n / 2 + (i - 1) / 2];
                }else{
                    narr[i] = arr[i/2];
                }
            }
            ans++;
            bool check = true;
            for(int i = 0;i<n;i++){
                check &= ogi[i] == narr[i];
            }
            
            if(check) break;
            arr = narr;
        }
        return ans;
    }
};