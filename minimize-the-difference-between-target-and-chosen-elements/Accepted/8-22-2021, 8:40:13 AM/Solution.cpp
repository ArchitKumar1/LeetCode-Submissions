// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        const int N = 71*71;
        
        bitset<N> oldbs;
        oldbs[0] = 1;
        
        int n = mat.size(),m = mat[0].size();
        for(int i = 0;i < n;i++){
            bitset<N> newbs;
            for(int j = 0;j < m;j++){
                newbs |= (oldbs << mat[i][j]);
            }
            oldbs = newbs;
        }
        int ans = INT_MAX;
        for(int i = 0;i < N;i++){
           if(oldbs[i] == 1) ans = min(abs(target - i),ans);
        }
        return ans;
    }
};