// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> l;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        l.push(num);
        while(s.size() < l.size()){
            s.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        if(s.size() == l.size()){
            return (1.0*s.top() + l.top())/2;
        }else{
            return (double)s.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */