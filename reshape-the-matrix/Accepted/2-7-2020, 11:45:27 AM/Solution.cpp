// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int R = nums.size();
        int C = nums[0].size();
        if(r*c != R*C){
            return nums;
        }
        vector<vector<int>> arr(r,vector<int> (c,0));
        int total = 0;
        for(int i = 0;i<R;i++){
            for(int j = 0;j<C;j++){
                int total = i*C + j;
                int x = total/c;
                int y = total%c;
                arr[x][y] = nums[i][j];
            }
        }
        return arr;
    }
};