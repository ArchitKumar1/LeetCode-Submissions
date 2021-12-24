// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans =0 ;
        for(string s : strs){
            int ones = 0;
            int zeros = 0;
            for(char c : s){
                ones+= (c == '1');
                zeros+=(c == '0');
            }
            ans += ((ones<=n) && (zeros <=m));
        }
        return ans;
    }
    
};