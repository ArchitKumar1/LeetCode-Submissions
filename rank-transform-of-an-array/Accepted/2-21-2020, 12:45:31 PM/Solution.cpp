// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vec = arr;
        sort(vec.begin(),vec.end());
        vec.resize(unique(vec.begin(),vec.end()) - vec.begin());
        map<int,int> m1;
        int pos = 1;
        for(int c : vec){
            m1[c] += pos;
            pos++;
        }
        vector<int> ans;
        for(int c : arr){
            ans.push_back(m1[c]);
        }
        return ans;
    }
};