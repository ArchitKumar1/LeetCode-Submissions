// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        int temp =0;
        stack<char> st;
        for(char c : s){
            if(c == '('){
                if(st.empty())temp =0;
                st.push(c);
            }
            if(c == ')'){
                if(st.size() == 0){
                    continue;
                    temp =0;
                }else{
                    st.pop();
                    temp +=2;
                }
            }
            maxans = max(maxans,temp);
        }
        return maxans;
    }
};