// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while ( tx >= sx && ty >= sy ) {
            cout << tx << " " << ty << endl;
            
            if( tx > ty){
                if(ty == sy) return ((tx-sx) % sy == 0);
                tx %= ty;
                
            }else{
                if(tx == sx) return ((ty-sy) % sx == 0);
                ty %= tx;
            }
        }
        return 0;
    }
};