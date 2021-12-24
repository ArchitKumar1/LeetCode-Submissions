// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        vector<string> ops = {"+","-","*","/"};
        for(string s : tokens){
            bool done = 0;
            for(string op : ops){
                if(s == op){
                    int a = stoi(st.top()); st.pop();
                    int b = stoi(st.top()); st.pop();
                    int res = 0;
                    if(s == "+") res = a+b;
                    if(s == "*") res = a*b;
                    if(s == "/") res = a/b;
                    if(s == "-") res = a-b;
                    st.push(to_string(res));
                    done = 1;
                }
            }
            if(!done) st.push(s);
        }
        return stoi(st.top());
    }
};