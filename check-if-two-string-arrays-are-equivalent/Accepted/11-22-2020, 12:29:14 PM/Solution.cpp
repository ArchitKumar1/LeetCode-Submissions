// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x,y;
        for(auto p : word1) x += p;
        for(auto p : word2) y += p;
        return x==y;
        
    }
};