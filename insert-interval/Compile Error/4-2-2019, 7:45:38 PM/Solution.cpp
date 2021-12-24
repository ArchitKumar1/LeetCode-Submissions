// https://leetcode.com/problems/insert-interval

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        intervals.push_back(newInterval);
        priority_queue<Interval,vector<Interval>,greater<Interval>> pq;
        for(auto c : intervals){
            pq.push(c);
        }
        while(!pq.empty()){
            Interval a = pq.top();
            pq.pop();
            int x = a.start;
            int y = a.end;
            
            while(!pq.empty()){
                Interval v = pq.top();
                pq.pop();
                if(y > v.start)
                    continue;
                else{
                    y = a.end;
                    break;
                }
            }
            
            
            ans.push_back({x,y});
        }
        return ans;
    }
};