// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
public:
    multiset<pair<int,int>> vec;
    MyCalendarThree() {
        int a = 1;
    }
    
    int book(int start, int end) {
        int ans = 0;
        int curr = 0;
        vec.insert({start,1});
        vec.insert({end,-1});
        for(auto it =  vec.begin();it!= vec.end();it++){
            pair<int,int> p =(*it);
            if(p.second  == -1){
                curr-=1;
            }else{
                curr+=1;
            }
            if(curr > ans){
                ans = curr;
            }
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */