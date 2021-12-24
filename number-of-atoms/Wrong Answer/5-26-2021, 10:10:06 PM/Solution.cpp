// https://leetcode.com/problems/number-of-atoms

class Solution {
public:
    
    map<string,int> m1;
    bool ischar(char c){
        return islower(c) || isupper(c);
    };
    bool islower(char c){
        return (c>='a' && c<='z');
    };
    bool isupper(char c){
        return (c>='A' && c<='Z');
    };
    bool isnum(char c){
        return (c>='0' && c<='9');
    };
    map<string,int> solve(vector<string> vs){
        print(vs);
        stack<string> st;
        vector<string> next;
        map<string,int> m1;
        for(auto x : vs){
    
            if(x == string(1,'(') || x == string(1,')')){
                st.push(x);
            }else if(isnum(x[0])){
                next = vector<string>();
                
                if(st.top() == string(1,')')){
                                    
                    st.pop();
                    while(st.top()!=string(1,'(')){
                        next.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                    reverse(next.begin(),next.end());
                    map<string,int> m2 = solve(next);
                    for(auto y : m2){
                        m1[y.first] += stoi(x) * y.second;
                    }
                }else{
                    string t  = st.top();
                    m1[t] += stoi(x);
                    st.pop();
                }
                
            }else{
                st.push(x);
            }
            
        }
        while(st.size()){
                m1[st.top()]++;
                st.pop();
            }
        return m1;
        
    }
    void print(vector<string> splits){
        for(auto x : splits){
           cout << x << endl;
        }
        cout << "printed" << endl;
    }
    string countOfAtoms(string formula) {
                
        
        auto split = [&](string s) -> vector<string> {
            vector<string> splits;
            for(int i = 0;i < s.size();i++){
                char c = s[i];
                if( c == '(' || c == ')'){
                    splits.push_back(string(1,c));
                }
                else if(isnum(c)){
                    string t = string(1,s[i]);
                    while(i + 1 < s.size() && isnum(s[i+1])){
                        t += s[i+1];
                        i++;
                    }
                    splits.push_back(t);
                }
                else if(ischar(c)){
                    string t = string(1,s[i]);
                    while(i + 1 < s.size() && islower(s[i+1])){
                        t += s[i+1]; 
                        i++;
                    }
                    splits.push_back(t);
                }
            }
            return splits;
        };
        vector<string> splits = split(formula);
        
        
        
        
        map<string,int>m1 =  solve(splits);
        string ans = "";
        for(auto x : m1){
            ans += x.first;
            if(x.second  > 1){
                ans += to_string(x.second);
            }
        }
        return ans;
    }
};