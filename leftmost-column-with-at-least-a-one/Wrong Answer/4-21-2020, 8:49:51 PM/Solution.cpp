// https://leetcode.com/problems/leftmost-column-with-at-least-a-one

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int n = d[0];
        int m = d[1];
        
//         int ans = INT_MAX;
//         for(int i = 0;i<n;i++){
//             int l = 0;
//             int h = m-1;
            
//             int t = INT_MAX;
//             while(l<=h){
//                 int mid = (l+h)/2;
//                 int x = binaryMatrix.get(i,mid);
//                 if(x == 1){
//                     t = mid;
//                     h = mid-1;
//                 }else{
//                     l = mid+1;
//                 }
//             }
//             ans = min(ans,t);
//         }
//         return ans == INT_MAX ? -1 : ans;
        
        int ans = INT_MAX;
        int x = 0;
        int y = m-1;
        
        while( x >= 0 && x < n && y>=0 && y<m){
            cout << x << " " << y << endl;
            int g = binaryMatrix.get(x,y);
            if(g == 1){
                ans = min(ans,y);
                x--;
            }else{
                y++;
            }
        }
        return ans == INT_MAX ? -1 : ans; 
        
        
    }
};