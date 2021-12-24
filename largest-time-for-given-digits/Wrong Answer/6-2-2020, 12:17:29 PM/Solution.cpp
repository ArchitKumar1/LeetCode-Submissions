// https://leetcode.com/problems/largest-time-for-given-digits

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "0";
        sort(A.begin(),A.end());
        do{
            int h = A[0] *10 + A[1];
            int m = A[2] *10 + A[3];
            if( h>= 0 && h<=23 && m>=0 && m<=59){
                ans = max(ans,to_string(A[0]) + to_string(A[1]) + ":"+to_string(A[2]) + to_string(A[3]));
            }
        }
        while(next_permutation(A.begin(),A.end()));
        return ans;
        
    }
};