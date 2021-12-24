// https://leetcode.com/problems/detect-squares

struct HASH{
  size_t operator()(const array<int,2>&x)const{
    return hash<long long>()(((long long)x[0])^(((long long)x[1])<<32));
  }
};
class DetectSquares {
public:
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {-1,1,-1,1};
    unordered_map<array<int,2>,int,HASH> m1;
    DetectSquares() {
        m1.reserve(5000);
        m1.max_load_factor(0.25);
    }
    int OFFSET = 1100;
    void add(vector<int> point) {
        
        m1[{point[0] + OFFSET,point[1] + OFFSET}]++;
    }
   
    int N = 1000;
    int count(vector<int> point) {
        int ans = 0;
        for(int k = 0;k < 4;k++){
            int x = point[0] + OFFSET;
            int y = point[1] + OFFSET;
            array<int,2> a = {x,y},b= {x,y},c = {x,y},d = {x,y};
            int M = N;
            while(M--){
                if( c[0] - OFFSET > 1000 || c[1] - OFFSET > 1000 || c[0] - OFFSET < 0 || c[1] - OFFSET< 0 ) break;

                a[0] += dx[k];
                b[1] += dy[k];
                c[0] += dx[k];
                c[1] += dy[k];
                int cnt = m1[a] * m1[b] * m1[c];
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