// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string A, string B) {
        
        if(A.size() == B.size() && A.size() <= 1) return A == B;
        bool ans  = 0;
        
        int N = A.size();
        
        while(N--){
            A = A.substr(1) + A[0];
            ans |= (A == B);
            cout << A << " " << B << endl;
        }
        return ans;
    }
};