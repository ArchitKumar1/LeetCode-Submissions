// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m1;
        for(int c :arr){
            m1[c] +=1;
        }
        int ans = -1;
        for(auto x : m1){
            if(x.first == x.second);
            ans = x.first;
        }
        return ans;
    }
};