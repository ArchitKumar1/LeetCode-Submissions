// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& C) {
        set<int> s;
        for(int c :C )s.insert(c);
        int n = C.size();
        int m = s.size();
        return 2*m>=n ? n/2 : m;
    }
};