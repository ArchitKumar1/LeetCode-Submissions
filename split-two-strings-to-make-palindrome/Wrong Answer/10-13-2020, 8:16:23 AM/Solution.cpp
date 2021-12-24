// https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution {
public:
    bool pali(string x){
        int i = 0;
        int j = x.size() - 1;
        while(i<j){
            if(x[i]!=x[j]) return 0;
            i++,j--;
        }
        return 1;
    }
    bool checkPalindromeFormation(string a, string b) {
        if(pali(a) || pali(b)) return 1;
        
        int n = a.size();
        int i = 0;
        int j = n-1;
        
        bool ok1 = 1;
        int jumps = 1;
        string A = a,B = b;
        while(i<j){
            if( A[i] == B[j]){
                i++,j--;
            }else{
                if(jumps == 1){
                    jumps = 0;
                    B = A;
                }else{
                    ok1 = 0;
                    break;
                }
            }
        }
        
        i = 0;
        j = n-1;
        bool ok2 = 1;
        jumps = 1;
        A = a,B = b;
        while(i<j){
            if( B[i] == A[j]){
                i++,j--;
            }else{
                if(jumps == 1){
                    jumps = 0;
                    A = B;
                }else{
                    ok2 = 0;
                    break;
                }
            }
        }
        return ok1|ok2;
    }
};