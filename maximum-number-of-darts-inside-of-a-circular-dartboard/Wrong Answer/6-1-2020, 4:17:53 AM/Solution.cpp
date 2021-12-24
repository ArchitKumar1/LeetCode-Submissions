// https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard

class Solution {
public:
    
    double cx,cy;
    double r;
    void findCircle(int x1, int y1, int x2, int y2, int x3, int y3) 
    { 
        int x12 = x1 - x2; 
        int x13 = x1 - x3; 

        int y12 = y1 - y2; 
        int y13 = y1 - y3; 

        int y31 = y3 - y1; 
        int y21 = y2 - y1; 

        int x31 = x3 - x1; 
        int x21 = x2 - x1; 

        // x1^2 - x3^2 
        int sx13 = pow(x1, 2) - pow(x3, 2); 

        // y1^2 - y3^2 
        int sy13 = pow(y1, 2) - pow(y3, 2); 

        int sx21 = pow(x2, 2) - pow(x1, 2); 
        int sy21 = pow(y2, 2) - pow(y1, 2); 

        int f = ((sx13) * (x12) 
                 + (sy13) * (x12) 
                 + (sx21) * (x13) 
                 + (sy21) * (x13)) 
                / (2 * ((y31) * (x12) - (y21) * (x13))); 
        int g = ((sx13) * (y12) 
                 + (sy13) * (y12) 
                 + (sx21) * (y13) 
                 + (sy21) * (y13)) 
                / (2 * ((x31) * (y12) - (x21) * (y13))); 

        int c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1; 
        int h = -g; 
        int k = -f; 
        int sqr_of_r = h * h + k * k - c; 

        // r is the radius 
        double radius = sqrt(sqr_of_r); 

        cx = h;
        cy = k;
        r = radius;
    } 
    
    bool in(int x,int y){
        double dist = pow(cx-x,2) + pow(cy-y,2) - r*r;
        return dist <=0;
    }
    bool col(int x1, int y1, int x2, int y2, int x3, int y3) {
        int a = x1 * (y2 - y3) +  
            x2 * (y3 - y1) +  
            x3 * (y1 - y2); 
        return a == 0;
    }
    int numPoints(vector<vector<int>>& p, int R) {
        int n = p.size();
        int best = 0;
        for(int i =0 ;i+2<n;i++){
            for(int j = i+1;j+1<n;j++){
                for(int k = j+1;k<n;k++){
                    if(col(p[i][0],p[i][1],p[j][0],p[j][1],p[k][0],p[k][1]) == 1) continue;
                    findCircle(p[i][0],p[i][1],p[j][0],p[j][1],p[k][0],p[k][1]);
                    int curr = 0;
                    for(int l = 0;l<n;l++){
                        if(in(p[l][0],p[l][1]) && r <=R) curr++;
                    }
                    best = max(best,curr);
                }
            }
        }
        return best;
    }
};