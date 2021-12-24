// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        map<long long ,int> m1;
        set<long long int> s ;
        s.insert(1LL);
        long long int ans = 0;
        while(n--){
            long long int f = *s.begin();
            s.erase(s.begin());
            ans = f;
            for( int x : vector<int>({2,3,5})){
                if(m1[f*x] == 0){
                    m1[f*x] = 1;
                    s.insert(f*x);
                }
            }
        }
        return ans;
    }
};