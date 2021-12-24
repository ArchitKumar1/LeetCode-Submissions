// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
        vector<int> l(n,0),r(n,n-1);
        int ans = 0;
        vector<int> st;
        for(int i = 0;i < n;i++){
            // l to r increasing to find the smaller h on the left that is smaller
            while(st.size() && heights[st.back()] >= heights[i]){
                st.pop_back();
            }
            if(st.size() == 0){
                l[i] = 0;
            }else{
                l[i] =  st.back()+1;
            }
            st.push_back(i);
        }
        st.clear();
        for(int i = n-1;i>= 0;i--){
            // r to l decreasing to find the smaller h on the right that is smaller
            while(st.size() && heights[st.back()] >= heights[i]){
                st.pop_back();
            }
            if(st.size() == 0){
                r[i] = n-1;
            }else{
                r[i] =  st.back()-1;
            }
            st.push_back(i);
        }
        for(int i = 0;i < n;i++){
            int width = r[i] - l[i] + 1;
            // cout << l[i] << " " << r[i] << endl;
            int area = heights[i] * width;
            ans = max(ans,area);
        }
        return ans;
        
    }
};