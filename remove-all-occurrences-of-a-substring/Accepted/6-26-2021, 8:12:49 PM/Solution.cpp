// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    int find_substring(string str, string pattern) {
        if( str.size() == 0 || pattern.size() == 0)
            return -1;
        int patt[pattern.size()];
        std::fill( patt, patt+pattern.size(), -1);
        for(int r=1, l=-1; r<pattern.size(); r++) {

            while( l != -1 && pattern[l+1] != pattern[r])
                l = patt[l];
            if( pattern[l+1] == pattern[r])
                patt[r] = ++l;
        }
        int tail = -1;
        for(int i=0; i<str.size(); i++) {
            while( tail != -1 && str[i] != pattern[tail+1])
                tail = patt[tail];
            if( str[i] == pattern[tail+1])
                tail++;
            if( tail == pattern.size()-1)
                return i - tail;
        }
        return -1;
    }
    string removeOccurrences(string s, string part) { 
        while(true){
            int x =  find_substring(s,part);
            if(x == -1) break;
             s.erase(s.begin()+x,s.begin()+x + part.size());
        }
        return s;
    }
};