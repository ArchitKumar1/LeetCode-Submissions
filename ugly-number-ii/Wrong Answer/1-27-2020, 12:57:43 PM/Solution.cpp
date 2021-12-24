// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int> s;
        s.insert(1);
        long long int ans = -1;
        for(int i = 1;i<=n;i++){
            ans = *s.begin();
            s.insert(2*i);
            s.insert(3*i);
            s.insert(5*i);
            s.erase(*s.begin());
        }
        return ans;
    }
};