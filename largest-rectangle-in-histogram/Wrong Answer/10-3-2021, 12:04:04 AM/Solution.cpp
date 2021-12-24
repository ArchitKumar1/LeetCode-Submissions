// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        vector<int> h = H;
        h.push_back(0);
        int n = h.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0;i < n;i++){
            while(st.size() && h[st.top()] > h[i]){
                int H = h[st.top()];
                int W = i - st.top();
                ans = max(ans,H*W);
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};