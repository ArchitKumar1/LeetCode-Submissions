// https://leetcode.com/problems/design-front-middle-back-queue

class FrontMiddleBackQueue {
public:
    vector<int> ans;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        ans.insert(ans.begin(),val);
    }
    
    void pushMiddle(int val) {
        ans.insert(ans.begin() + (ans.size())/2,val);
    }
    
    void pushBack(int val) {
        ans.push_back(val);
    }
    
    int popFront() {
        if(!ans.size()) return -1;
        int fans = ans[0];
        ans.erase(ans.begin());
        return fans;
    }
    
    int popMiddle() {
        if(!ans.size()) return -1;
        int fans = ans[ans.size()/2];
        ans.erase(ans.begin()+ ans.size()/2);
        return fans;
        
    }
    
    int popBack() {
        if(!ans.size()) return -1;
        int fans = ans[ans.size()-1];
        ans.erase(ans.begin()+ans.size()-1);
        return fans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */