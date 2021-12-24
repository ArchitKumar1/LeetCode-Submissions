// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
        double h = hour + 1.0*minutes/60;
        double hangle = 1.0*360/12 * h;
        
        double mangle = 1.0*360/60 * minutes;
        return min(abs(hangle - mangle),360-abs(hangle-mangle));
        
    }
};