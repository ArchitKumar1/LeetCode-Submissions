// https://leetcode.com/problems/string-matching-in-an-array

class Solution {
public: 
    bool ok(string a,string b){
        int n = a.size();
        int m = b.size();
        if(m >= n) return 0;
        
        bool safe= 0 ;
        for(int i = 0;i<n-m+1;i++){
            safe |=  (a.substr(i,m) == b);
        }
        return safe;
        
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> all;
        for(string s : words){
            bool done = 0;
            for(string t : words){
                done |= ok(t,s);
            }
            all.push_back(s);
        }
        return all;
    }
};