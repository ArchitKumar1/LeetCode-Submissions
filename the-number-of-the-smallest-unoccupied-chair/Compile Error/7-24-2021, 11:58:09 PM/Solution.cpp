// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<array<int,3>> v;
        int n = times.size();
        int pos = 0;
        for(auto x : times){
            v.push_back({-1,x[1],pos});
            v.push_back({1,x[0],pos});
            pos++;
        }
        sort(v.begin(),v.end());
        set<int> free;
        vector<int> seats(n);
        for(int i = 0;i < n;i++) free.insert(i);
        for(auto e : v){
            auto[ty,t,i] = e;
            if(ty == -1) free.insert(seats[i]);
            else(ty == 1){
                int seat = *free.begin();
                seats[i] = seat;
                free.erase(free.begin());
            }
        }
        return seats[targetFriend];
    }
};