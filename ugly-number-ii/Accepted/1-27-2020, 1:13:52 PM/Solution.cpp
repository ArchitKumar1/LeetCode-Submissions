// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> s;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> m1;
        s.insert(1);
        vector<int> primes({2,3,5});
        long long int ans = -1;
        for(int i = 1;i<=n;i++){
            ans = *s.begin();
            for(int x : primes ){
                if(m1.find(ans*x) == m1.end()){
                    s.insert(ans*x);
                    m1[ans*x]= 1;
                }
            }
            s.erase(*s.begin());
        }
        return ans;
    }
};