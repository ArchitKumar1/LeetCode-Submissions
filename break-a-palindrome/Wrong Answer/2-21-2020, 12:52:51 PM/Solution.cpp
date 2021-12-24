// https://leetcode.com/problems/break-a-palindrome

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ans ="";
        int cnta = 0;
        for( char c : palindrome){
            cnta += c == 'a';
        }
        if(n%2 == 0){
            bool ok = 0;
            if(cnta != n){
                for( char c : palindrome){
                    if( c != 'a' && !ok){
                        ans += 'a';
                        ok = 1;
                    }else{
                        ans += c;
                    }
                }
            }else{
                if(ok == 0){
                    ans= palindrome;
                     ans[n-1] = 'b';
                }
                
            }
        }else{
            bool ok = 0;
            if(cnta != n){
                for( int i =0;i<n;i++){
                    if(i == n/2) continue;
                    char c = palindrome[i];
                    if( c != 'a' && !ok){
                        ans += 'a';
                        ok = 1;
                    }else{
                        ans += c;
                    }
                }
            }else{
                if(ok == 0){
                    ans= palindrome;
                     ans[n-1] = 'b';
                }
                
            }
        }
        return ans;
    }
};