// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> seive(n + 1,1);
        int cnt = 0;
        for(int i=2;i<=sqrt(n);i++){
            if(seive[i] == 1){
                for(int j=i*i;j<=n;j=j+i){
                    seive[j] = 0;
                }
                cnt++;
            }
        }
            
        // for(int i=2;i<n;i++)
        //     if(seive[i])
        //         cnt++;
         return cnt;
    }
};