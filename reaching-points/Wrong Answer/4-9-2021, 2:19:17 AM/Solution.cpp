// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while ( tx > sx && ty > sy ) {
            // if( tx > ty) tx = tx%ty == 0 ? ty : tx%ty;
            // else ty = ty%tx == 0 ? tx : ty%tx;
            if( tx > ty) tx -= ty;
            else ty -=tx;
            if(tx == sx && ty == sy) return 1;
            if(tx == ty) break;
        }
        return 0;
    }
};