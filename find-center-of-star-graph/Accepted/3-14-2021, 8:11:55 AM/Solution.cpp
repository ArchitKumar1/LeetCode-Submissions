// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int,int> m1;
        for(auto x :edges){ 
            m1[x[0]]++;
            m1[x[1]]++;
        }
        for(auto x : m1){
            if(x.second == n) return x.first;
        }
        return 0;
    }
};