// https://leetcode.com/problems/min-stack

class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    
    void push(int x) {
        st1.push(x); 
        if(st2.empty() || x <=getMin())
            st2.push(x);
    }
    
    void pop() {
        if(st1.top() == getMin())
            st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */