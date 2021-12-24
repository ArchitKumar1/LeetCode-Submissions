// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        int n = as.size();
        stack<int> st;
        for(int i = 0;i<n;i++){
            st.push(as[i]);
            bool safe = 1;
            cout << i << " " << st.size() <<  endl;
            while(st.size() >= 2 && safe){
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                cout << a << " " << b << endl;
                if(a *b  < 0){
                    cout << "unsafe" << endl;
                    if(abs(a) > abs(b)){
                        st.push(a);
                    }else{
                        st.push(b);
                    }
                }else{  
                    safe = 0;
                    st.push(b);st.push(a);
                    cout << "safe" <<  i << endl;
                }
                
            }
        }
        vector<int> res;
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
};