// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}
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
            else{
                int seat = *free.begin();
                seats[i] = seat;
                trace(ty,t,i,seat);
                free.erase(free.begin());
            }
        }
        return seats[targetFriend];
    }
};