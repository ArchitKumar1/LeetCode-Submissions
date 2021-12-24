// https://leetcode.com/problems/ugly-number-ii

class Solution {
public:
    int nthUglyNumber(int n) {
        map<int,int> m1;
        set<int> s ;
        s.insert(1);
        int ans = 0;
        while(n--){
            int f = *s.begin();
            s.erase(s.begin());
            ans = f;
            for(int x : vector<int>({2,3,5})){
                if(m1[f*x] == 0){
                    m1[f*x] = 1;
                    cout << f*x << endl;
                    s.insert(f*x);
                }
            }
        }
        return ans;
    }
};