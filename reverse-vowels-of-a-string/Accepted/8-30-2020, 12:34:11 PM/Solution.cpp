// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        string v = "aeiouAEIOU";
        vector<int> pos;
        int i = 0;
        for(char c : s){
            for(char d : v){
                if(c == d){
                    pos.push_back(i);
                }
            }
            i++;
        }
        for(int i =0 ;i<pos.size()/2;i++){
            swap(s[pos[i]],s[pos[pos.size()-1-i]]);
        }
        return s;
    }
};