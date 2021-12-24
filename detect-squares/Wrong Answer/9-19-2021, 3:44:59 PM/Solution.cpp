// https://leetcode.com/problems/detect-squares

class DetectSquares {
public:
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {-1,1,-1,1};
    map<array<int,2>,int> m1;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        m1[{point[0],point[1]}]++;
    }
   
    int N = 20;
    int count(vector<int> point) {
         auto print = [&](array<int,2> arr){
        cout <<  " " << arr[0] << " " << arr[1] << endl;
    };
        int ans = 0;
        for(int k = 0;k < 4;k++){
            int x = point[0];
            int y = point[1];
            array<int,2> a = {x,y},b= {x,y},c = {x,y},d = {x,y};
            print(a);
            print(b);
            print(c);
            print(d);
            int M = N;
            cout << "point" << endl;
            print({x,y});
            cout << "BS" << k << endl;
            while(M--){
                cout << M << endl;
                print(a);
                print(b);
                print(c);
                print(d);
                a[0] += dx[k];
                b[1] += dy[k];
                c[0] += dx[k];
                c[1] += dy[k];
                int cnt = 1;
                cnt *= m1[a];
                cnt *= m1[b];
                cnt *= m1[c];
                cnt *= m1[d];
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