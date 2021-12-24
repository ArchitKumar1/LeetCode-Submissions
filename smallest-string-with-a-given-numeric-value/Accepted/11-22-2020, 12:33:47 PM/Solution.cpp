// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value

class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> s(n,0);
        for(int i =n-1;i>=0;i--){
            int buffer = i;
            int rest = k - buffer;
            if(rest >= 26){
                s[i] = 26;
                k-= 26;
            }else{
                s[i] = rest;
                k -= rest;
            }
        }
        string ans;
        for(int c : s){
            ans += ('a' + c-1);
        }
        return ans;
    }
};