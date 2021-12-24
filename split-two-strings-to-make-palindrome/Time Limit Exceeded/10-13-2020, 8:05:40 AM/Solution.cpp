// https://leetcode.com/problems/split-two-strings-to-make-palindrome

class Solution {
public:
    bool pali(string x){
        int i = 0;
        int j = x.size() - 1;
        while(i<j){
            if(x[i]!=x[j]) return 0;
        }
        return 1;
    }
    bool checkPalindromeFormation(string a, string b) {
        if(pali(a) || pali(b)) return 1;
        
        int n = a.size();
        int i = 0;
        int j = n-1;
        bool ok1 = 1;
        while(i<j){
            ok1&= a[i] == b[j];
            i++,j--;
        }
        
        i = 0;
        j = n-1;
        bool ok2 = 1;
        while(i<j){
            ok2&= b[i] == a[j];
            i++,j--;
        }
        return ok1|ok2;
    }
};