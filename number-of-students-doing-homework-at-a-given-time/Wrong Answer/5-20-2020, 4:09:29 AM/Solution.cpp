// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time

class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        vector<pair<int,int>> v;
        for(int i = 0;i<s.size();i++){
            v.push_back({s[i],1});
            v.push_back({e[i],-1});
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        for(auto x : v){
            if(x.first > q && x.second == -1)break;
            if(x.second == 1) cnt +=1;
            else cnt -=1;
        }
        return cnt;
    }
};