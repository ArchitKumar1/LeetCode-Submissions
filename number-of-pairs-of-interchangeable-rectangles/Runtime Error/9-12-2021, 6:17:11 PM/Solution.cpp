// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& R) {
        int ans = 0;
        map<pair<int,int>,int> m1;
        
        for(auto r : R){
            int x = r[0],y = r[1];
            int g = __gcd(x,y);
            x /= g,y /=g;
            ans += m1[{x,y}];
            m1[{x,y}]++;
        }
        
        
        
        return ans;
        
    }
};