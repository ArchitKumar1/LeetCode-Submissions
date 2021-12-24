// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int>  ans;
        map<int,int> m1;
        for(int k=0;k<=22;k++){
            m1[pow(x,k)]++;
        }
         
        return vector<int>(ans.begin(),ans.end());
    }
};