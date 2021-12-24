// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

class Solution {
public:
    int minimumDeletions(string s) {
        while(s.size() && s.front() == 'a'){
            s.erase(s.begin());
        }
        while(s.size() && s.back() == 'b'){
            s.pop_back();
            cout << s << endl;
            
        }
        if(s.size() == 0){
            return 0;
        }
        int x = count(s.begin(),s.end(),'a');
        int y = count(s.begin(),s.end(),'b');
        return min(x,y);
    }
};