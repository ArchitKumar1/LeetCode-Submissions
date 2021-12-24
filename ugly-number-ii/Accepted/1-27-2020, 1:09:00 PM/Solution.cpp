// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> s;
        map<int,int> m1;
        s.insert(1);
        vector<int> primes({2,3,5});
        long long int ans = -1;
        for(int i = 1;i<=n;i++){
            ans = *s.begin();
            for(int x : primes ){
                if(m1[ans*x]!=1){
                    s.insert(ans*x);
                    m1[ans*x]= 1;
                }
            }
            s.erase(*s.begin());
        }
        return ans;
    }
};