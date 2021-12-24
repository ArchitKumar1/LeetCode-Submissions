// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m1;
        for(char c : s)m1[c]--;
        for(char c : t)m1[c]++;
        for(auto x : m1){
            if(x.second == 1){
                return x.first;
            }
        }
        return 'a';
    }
};