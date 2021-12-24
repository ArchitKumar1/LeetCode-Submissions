// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = 0.0;
        hour = hour%12;
        double h = hour + 1.0*minutes/60;
        double hangle = 1.0*360/12 * h;
        
        double mangle = 1.0*360/60 * minutes;
        
        return abs(hangle - mangle);
        
    }
};