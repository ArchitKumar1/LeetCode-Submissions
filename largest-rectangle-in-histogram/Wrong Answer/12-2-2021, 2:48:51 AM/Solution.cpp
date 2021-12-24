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
            while( st.size() && h[st.top()] > h[i]){
                int H = h[st.top()];
                int W = i - st.top(); 
                if(!st.size()) W++;
                ans = max(ans,H*W);
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

// def largestRectangleArea(self, height):
//     height.append(0)
//     stack = [-1]
//     ans = 0
//     for i in xrange(len(height)):
//         while height[i] < height[stack[-1]]:
//             h = height[stack.pop()]
//             w = i - stack[-1] - 1
//             ans = max(ans, h * w)
//         stack.append(i)
//     height.pop()
//     return ans
