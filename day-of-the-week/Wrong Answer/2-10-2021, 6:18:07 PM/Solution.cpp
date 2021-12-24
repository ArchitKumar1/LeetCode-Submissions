// https://leetcode.com/problems/day-of-the-week

class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        vector<string> ans = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        auto calc = [&](int y, int m, int d){
          static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
          y -= m < 3;
          return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
        };
        
        return ans[calc(d,m,y)+6 % 7];
    }
};