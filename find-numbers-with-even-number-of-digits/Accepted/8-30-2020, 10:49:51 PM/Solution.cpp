// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int c : nums){
            int d = 0;
            while(c){
                d++,c/=10;
            }
            if(d%2==0)ans++;
        }
        return ans;
    }
};