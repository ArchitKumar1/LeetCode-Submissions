// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x,y;
        for(auto p : wordl1) x += p;
        for(auto p : wordl2) y += p;
        return x==y;
        
    }
};