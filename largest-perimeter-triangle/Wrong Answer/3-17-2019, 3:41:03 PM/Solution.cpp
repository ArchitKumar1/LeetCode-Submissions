// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int ans = 0;
        for(int i=0;i<3;i++){
            auto x = max_element(A.begin(),A.end());
            int y = *x;
            ans += y;
            A.erase(x);
        }
        return ans;
    }
};