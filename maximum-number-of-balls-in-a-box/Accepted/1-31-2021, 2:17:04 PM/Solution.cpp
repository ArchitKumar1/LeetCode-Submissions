// https://leetcode.com/problems/maximum-number-of-balls-in-a-box

class Solution {
public:
    int countBalls(int l, int h) {
        map<int,int> m1;
        
        for(int x =l;x<=h;x++ ){
            int ans = 0;
            int y = x;
            while(y){
                ans += y%10;
                y/=10;
            }
            m1[ans]++;
        }
        int ans = INT_MIN;
        for(auto x : m1){
            ans = max(ans,x.second);
        }
        return ans;
    }
};