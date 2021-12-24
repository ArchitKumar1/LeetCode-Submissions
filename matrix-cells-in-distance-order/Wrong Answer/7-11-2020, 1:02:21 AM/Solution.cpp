// https://leetcode.com/problems/matrix-cells-in-distance-order

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> all;
        for(int i=0;i<R;i++){
            for(int j = 0;j<C;j++){
                all.push_back({i,j});
            }
        }
        sort(all.begin(),all.end(),[&](vector<int> a,vector<int>b){
            int x =  pow(r0-a[0],2) + pow(c0-a[1],2);
            int y =  pow(r0-b[0],2) + pow(c0-b[1],2);
            return sqrt(x) < sqrt(y);
            
        });
        return all;
    }
};