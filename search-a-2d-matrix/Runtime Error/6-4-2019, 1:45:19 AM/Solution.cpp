// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        if(n == 0 ||m==0) return 0;
        
        int low = 0;
        int high = (n-1)*(m-1);
        
        while( low<=high){
            int mid = (low+high) / 2;
            if(target == matrix[mid/n][mid%m]) 
                return 1;
            else if(target > matrix[mid/n][mid%m]){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return 0;
    }
};