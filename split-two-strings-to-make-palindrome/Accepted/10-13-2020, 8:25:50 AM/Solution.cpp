// https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution {
public:
    bool pali(string x,int i,int j){
        while(i<j){
            if(x[i]!=x[j]) return 0;
            i++,j--;
        }
        return 1;
    }
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        if(pali(a,0,n-1) || pali(b,0,n-1)) return 1;
        
        
        int i = 0;
        int j = n-1;
        
        bool ok1 = 1;
        string A = a,B = b;
        while(i<j){
            if( A[i] == B[j]){
                i++,j--;
            }else{
                ok1 = pali(a,i,j) | pali(b,i,j);
                break;
                
            }
        }
        
        i = 0;
        j = n-1;
        bool ok2 = 1;
        A = a,B = b;
        while(i<j){
            if( B[i] == A[j]){
                i++,j--;
            }else{
                ok2 = pali(a,i,j) | pali(b,i,j);
                break;

            }
        }
        return ok1|ok2;
    }
};