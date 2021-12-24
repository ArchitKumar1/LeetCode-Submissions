// https://leetcode.com/problems/the-score-of-students-solving-math-expression

class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = answers.size();
        vector<int> ans(n);
        
        int m = s.size();
        vector<string> vs;
        
        for(int i = 0;i < m;i++){
            char c = s[i];
            
            vs.push_back(string(1,c));
        }
        
        auto parse = [&](vector<string> v) -> int{
            stack<string> st;
           
            for(int i = 0;i < v.size();i++){
                // cout << v[i] << " ";
                string s = v[i];
                 if(st.size() && st.top() == "*"){
                    st.pop();
                    string t = st.top();
                    st.pop();
                    st.push(to_string(stoi(s) * stoi(t)));
                }else{
                    st.push(s);
                }
            }
            // cout << endl;
            v.clear();
            while(st.size()){
                v.push_back(st.top());
                st.pop();
            }
            reverse(v.begin(),v.end());
            for(int i = 0;i < v.size();i++){
                string s = v[i];
                if(st.size() && st.top() == "+"){
                    st.pop();
                    string t = st.top();
                    st.pop();
                    st.push(to_string(stoi(s) + stoi(t)));
                }else{
                    st.push(s);
                }
            }
            
            return stoi(st.top());
        };
        
        
        int M = m/2;
        
        int correct = parse(vs);
        // cout << correct << endl;
        map<int,int> half;
        for(int i = 0;i < 1 << M;i++){
            vector<string> vstemp = vs;
            for(int j = 0; j < M;j++){
                if( i >> j & 1){
                    if(vs[2*j + 1] == "+") vstemp[2*j + 1] = "*"; 
                    else vstemp[2*j + 1] = "+";
                }
                
            }
            int hc = parse(vstemp);
            // cout << hc << endl;
            half[hc] = 1;
            
        }
        for(int i = 0;i < n;i++){
            if(answers[i] == correct) ans[i] = 5;
            else if(half[answers[i]]) ans[i] = 2;
            else ans[i] = 0;
        }
        int fans = 0;
        for(int c : ans)  fans += c;
        return fans;

    }
};