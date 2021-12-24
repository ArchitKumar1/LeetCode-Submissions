// https://leetcode.com/problems/nth-magical-number

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        
        
        long long int l = 0,h = 1e14;
        const int mod = 1e9+7;
        long long int ans = -1;
        const double eps = -1e6;
        while(l <= h){
            long long int mid = (l+h)/2;
            
            long long int cnt = 0;
            
            
            long long int gcd = __gcd(A,B);
            long long int lcm = A*B/gcd;
            
            cnt += mid/(A);
            cnt += mid/(B);
            cnt -= mid/(lcm);
            
            cout << mid << " " << cnt << endl;
            if(cnt < N){
                l = mid +1;
            }else{
                ans = mid;
                h = mid-1;
            }

            
        }
        return ans%mod;
    }
};