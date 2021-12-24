// https://leetcode.com/problems/goal-parser-interpretation

class Solution {
public:
    string interpret(string command) {
        map<string,string> m1 = {{"G","G"},{"()", "o"},{"(al)" ,"al"}};
        string s = "";
        string ans = "";
        
        for(char c : command){
            s +=c;
            if(m1.find(s)!=m1.end()){
                ans += m1[s];
                s = "";
            }
        }
        return ans;
    }
};