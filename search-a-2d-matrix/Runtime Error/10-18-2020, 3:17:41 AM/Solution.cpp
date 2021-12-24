// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix.front().size();
        int pos = -1;
        int low = 0;
        int high = n*m-1;
        
        while(low <= high){
            int mid = (low+high)>>1;
            if(matrix[mid/m][mid%m] == target){
                pos = 0;
                break;
            }else if( matrix[mid/m][mid%m] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return pos == 0;
    }
};