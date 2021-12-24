// https://leetcode.com/problems/k-concatenation-maximum-sum

#define LL long long
const int M = 1e9+7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        LL s = 0;
        for(int x : arr){
            s += x;
        }
        LL p = 0;
        LL c = 0;
        for(int x : arr){
            c +=x;
            p = max(p,c);
        }
        reverse(arr.begin(),arr.end());
        c = 0;
        LL su = 0;
        for(int x : arr){
            c +=x;
            su = max(su,c);
        }
        
        c = 0;
        LL kd = 0;
        for(int x : arr){
            c +=x;
            kd = max(kd,c);
            if(c < 0) c = 0;
        }
        
        LL a1 = 0;
        LL a2 = (LL)k*s;
        LL a3 =  (k>1)? p +su : 0;
        LL a4 = (k>2) ? p + su +((LL)k-2)*s : 0;
        LL a5 = kd;
        
        return max({a1,a2,a3,a4,a5}) % (M);
    }
};