// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prod = 1;
        string s = to_string(n);
        for(char c :s){
            sum += c-'0';
            prod*=(c-'0');
        }
        return prod-sum;
    }
};