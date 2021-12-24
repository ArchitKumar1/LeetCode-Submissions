// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.size() < b.size()) swap(a,b);
        
        int n = a.size();
        int m = b.size();

        
        b += string(n-m,'0');
        
        bool carry = 0;
        for(int i =0 ;i<n;i++){
            int x = a[i]-'0';
            int y = b[i]-'0';
            
            int sum = x + y + carry;
            if(sum >=2){
                carry = 1;
                ans += '0';
            }else{
                carry = 0;
                ans += '0' + sum;
            }
        }
        if(carry) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};