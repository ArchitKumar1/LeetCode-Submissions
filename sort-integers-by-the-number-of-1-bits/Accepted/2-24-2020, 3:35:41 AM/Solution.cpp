// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(),arr.end(),[&](int i ,int j){
           if(__builtin_popcount(i) != __builtin_popcount(j)){
                return( __builtin_popcount(i) < __builtin_popcount(j));
           }else{
               return i < j;
           }
       });
        return arr;
    }
};