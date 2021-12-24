// https://leetcode.com/problems/destination-city

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> m1;
        for(auto v : paths){
            m1[v[0]]++;
        }
        for(auto v : paths){
            if(m1[v[0]] == 0) return v[0];
            if(m1[v[1]] == 0) return v[1];
        }
        return "";
    }
};