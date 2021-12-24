// https://leetcode.com/problems/crawler-log-folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int pos = 0;
        for(string s : logs){
            if(s =="../") pos -=1;
            else if(s == "./") continue;
            else pos += 1;
        }
        return pos;
    }
};