// https://leetcode.com/problems/building-boxes

class Solution {
public:
    int minimumBoxes(int n) {
        long long int val = 1;
        
        
        while (val*(val+1)/2 <= n){
            val ++;
        }
        val--;
        return val*(val+1)/2;
    }
};