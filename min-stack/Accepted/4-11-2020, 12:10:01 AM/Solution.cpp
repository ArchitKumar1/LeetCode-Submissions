// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> n,m;
    MinStack() {
        
    }
    
    void push(int x) {
        if(n.size()){
            if(m.top() >= x){
                m.push(x);
            }
            n.push(x);
        }else{
            m.push(x);
            n.push(x);
        }
    }
    
    void pop() {

        if(m.top() == n.top()){
            m.pop();
        }
        n.pop();
    }
    
    int top() {
        return n.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */