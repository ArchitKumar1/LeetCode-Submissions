// https://leetcode.com/problems/count-largest-group

class Solution {
public:
    
    int countLargestGroup(int n) {
        
        auto get = [&](int x){
            int ans = 0;
            while(x){
                ans += x%10;x/=10;
            }
            return ans;
        };
        
        multiset<int> s;
        map<int,int> m1;
        for(int i = 1;i<=n;i++){
            cout << i << " " << get(i) << endl;
            s.insert(get(i));
        }
        for(auto x: s){
            cout << x << endl;
            m1[x]++;
        }
        return m1[*prev(s.end())];
        
    }
};