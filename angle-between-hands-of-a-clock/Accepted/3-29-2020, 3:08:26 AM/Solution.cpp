// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double m1 = minutes*6;
        double h1 = hour*30 + (double)minutes/2;
        
        return min(abs(h1-m1),abs(360-abs(h1-m1)));
    }
};