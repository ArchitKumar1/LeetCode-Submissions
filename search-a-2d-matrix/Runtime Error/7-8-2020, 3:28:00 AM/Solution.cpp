// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0;
        int h = n*m-1;
        
        while(l<=h){
            int mid = (l+h)>>1 ;
            int v = matrix[mid/n][mid%n];
            if( v == target){
                return 1;
            }else if(v > target){
                h = mid-1;
            }else{
                l =mid+1;
            }
        }
        return 0;
    }
};