// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        int n = as.size();
        stack<int> st;
        for(int i = 0;i<n;i++){
            st.push(as[i]);
            bool safe = 1;
            while(st.size() >= 2 && safe){
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                if(a < 0 && b > 0){
                    if(abs(b) > abs(a)){
                        st.push(b);
                    }else if(abs(b) < abs(a)){
                        st.push(a);
                    }else{
                        ;
                    }
                }else{  
                    safe = 0;
                    st.push(b);st.push(a);
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