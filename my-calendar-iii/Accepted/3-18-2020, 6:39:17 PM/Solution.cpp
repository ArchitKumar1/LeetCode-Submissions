// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
public:
    vector<pair<int,int>> vec;
    MyCalendarThree() {
        int a = 1;
    }
    
    int book(int start, int end) {
        int ans = 0;
        int curr = 0;
        vec.push_back({start,1});
        vec.push_back({end,-1});
        sort(vec.begin(),vec.end());
        for(pair<int,int> p : vec){
            if(p.second  == -1){
                curr-=1;
            }else{
                curr+=1;
            }
            ans= max(ans,curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */