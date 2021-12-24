// https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}
class Solution {
public:
    vector<double> findCircle(int x1, int y1, int x2, int y2, int x3, int y3){
        int x12 = x1 - x2;
        int x13 = x1 - x3;
        int y12 = y1 - y2;
        int y13 = y1 - y3;
        int y31 = y3 - y1;
        int y21 = y2 - y1;
        int x31 = x3 - x1;
        int x21 = x2 - x1;
        int sx13 = pow(x1, 2) - pow(x3, 2);
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
        double r = sqrt(sqr_of_r);
        return vector<double>({(double)h,(double)k,r});
    }
    
    bool collinear(int x1, int y1, int x2, 
               int y2, int x3, int y3){
        int a = x1 * (y2 - y3) + 
                x2 * (y3 - y1) + 
                x3 * (y1 - y2);
        return a==0;
    }
    
    bool inside(double x,double y,double h,double k,double r){
         double dist = (x-h)*(x-h)+(y-k)*(y-k);
         return dist <= (double)r*r;
    }
    int numPoints(vector<vector<int>>& points, int r) {
        
        int n = points.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                    int x1 = points[i][0], y1= points[i][1];
                    int x2 = points[j][0], y2= points[j][1];
                    int x3 = points[k][0], y3= points[k][1];
                    //trace(x1,y1,x2,y2,x3,y3);
                    if(collinear(x1,y1,x2,y2,x3,y3)) continue;
                    vector<double> c = findCircle(x1,y1,x2,y2,x3,y3);
                    double H = c[0],K = c[1],r = c[2];
                    //trace(H,K,r);
                    int tans = 0;
                    for(int l = 0;l<n;l++){
                        int x = points[l][0],y = points[l][1];
                        tans += inside(x,y,H,K,r);
                    }
                    ans = max(ans,tans);
                }
            }
        }
        return ans;
    }
};