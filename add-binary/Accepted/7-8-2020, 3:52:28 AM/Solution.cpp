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
        cout << a  << " " << b << endl;
        bool carry = 0;
        for(int i =0 ;i<n;i++){
            int x = a[i]-'0';
            int y = b[i]-'0';
            
            int sum = x + y + carry;
            if(sum == 0){
                carry = 0;
                ans += '0';
            }else if(sum == 1){
                carry = 0;
                ans += '1';
            }else if(sum == 2){
                carry = 1;
                ans += '0';
            }else{
                carry = 1;
                ans += '1';
            }
        }
        if(carry) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};