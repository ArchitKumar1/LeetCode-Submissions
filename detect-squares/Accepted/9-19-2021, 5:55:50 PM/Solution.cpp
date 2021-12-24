// https://leetcode.com/problems/detect-squares

struct HASH{
  size_t operator()(const array<int,2>&x)const{
    return hash<long long>()(((long long)x[0])^(((long long)x[1])<<32));
  }
};
class DetectSquares {
public:
    int m1[1001][1001] = {};
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {-1,1,-1,1};
    DetectSquares() {
    }
    void add(vector<int> point) {
        m1[point[0]][point[1]]++;
    }
  
    int count(vector<int> point) {
        long long ans = 0;
        for(int k = 0;k < 4;k++){
            int x = point[0];
            int y = point[1];
            array<int,2> a = {x,y},b= {x,y},c = {x,y},d = {x,y};
            while(true){
                a[0] += dx[k];
                b[1] += dy[k];
                c[0] += dx[k];
                c[1] += dy[k];
                if( c[0] > 1000 || c[1]> 1000 || c[0] < 0 || c[1]< 0 ) break;
                long long cnt = 1LL* m1[a[0]][a[1]] *  m1[b[0]][b[1]] *  m1[c[0]][c[1]] ;
                ans += cnt;
            }
        }
        return ans;
    
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */