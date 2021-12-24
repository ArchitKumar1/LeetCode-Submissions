// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& s) {
        double sum = 0;
        for(int c : s) sum += c;
        
        sum -= *max_element(s.begin(),s.end());
        sum -= *min_element(s.begin(),s.end());
        sum/=(s.size()-2);
        return sum;
    }
};