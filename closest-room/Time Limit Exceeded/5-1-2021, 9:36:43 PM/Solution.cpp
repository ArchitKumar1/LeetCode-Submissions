// https://leetcode.com/problems/closest-room


class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& q) {
        sort(rooms.begin(),rooms.end(),[&](vector<int> a,vector<int>b){
            return a[1] > b[1];
        });
        vector<array<int,3>> queries;
        queries.reserve(2*q.size());
        int i = 0;
        for(auto x : q){
            queries.push_back({x[0],x[1],i++});
        }
        sort(queries.begin(),queries.end(),[&](array<int,3> a,array<int,3>b){
            return a[1] > b[1];
        });
        
        int m = queries.size();
        int n = rooms.size();
        int j = 0;
        set<int> s;
        vector<int> res(m);
        for(int i = 0; i <  m;i++){
            while(j < n && rooms[j][1] >= queries[i][1]){
                s.emplace(rooms[j][0]);
                j++;
            }
            int pref = queries[i][0];
            int index = queries[i][2];
            
            if(s.size() == 0){ res[index] = -1; continue;}
            auto it = s.lower_bound(pref);
            if(it == s.end()){
                res[index] = *s.rbegin(); continue;
            }
            if(it != s.begin()){
                auto it2 = prev(it);
                int d1 = abs(pref - *it2);
                int d2 =  abs(*it - pref);
                if(d1 <= d2){
                    res[index] = *it2;
                }else{
                    res[index] = *it;
                }
            }else{
                res[index] = *it;
            }
        }
        
        return res;
    }
};