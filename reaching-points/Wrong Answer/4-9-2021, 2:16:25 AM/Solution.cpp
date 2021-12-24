// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while ( tx > sx && ty > sy ) {
            if( tx < ty) swap(tx,ty);
            tx = tx%ty == 0 ? ty : tx%ty;
            if(tx == sx && ty == sy) return 1;
            if(tx == ty) break;
        }
        return 0;
    }
};