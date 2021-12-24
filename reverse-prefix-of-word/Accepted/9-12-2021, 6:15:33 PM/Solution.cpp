// https://leetcode.com/problems/reverse-prefix-of-word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto it = find(word.begin(),word.end(),ch);
        if(it == word.end()) return word;
        reverse(word.begin(),it+1);
        return word;
    }
};