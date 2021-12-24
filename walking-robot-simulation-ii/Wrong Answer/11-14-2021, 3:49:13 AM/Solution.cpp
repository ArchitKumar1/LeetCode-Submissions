// https://leetcode.com/problems/walking-robot-simulation-ii

#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);}
class Robot {
public:
    // R U L D
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    vector<string> dirs = { "East", "North" ,"West", "South"};
    int n,m;

    int x = 0,y = 0;
    int dir = 0;
    
    int wall(int d,int x,int y){
        if(d == 0) return n - x;
        if(d == 1) return m - y;
        if(d == 2) return x;
        if(d == 3) return y;
        return false;
    }
    bool isOncorner(){
        return ((x == 0 and y == 0) ||
                (x == 0 and y == m) ||
                (x == n and y == 0) ||
                (x == n and y == m));
    }
    Robot(int width, int height) {
        n = width -1;
        m = height -1;
    }
    
    bool onWall(){
        return x == 0 || y == 0 || x == n || y == m;
    }
    void move(int num) {
        while(num > 0){
            if(isOncorner()){
                num %= (2*m + 2*n  + 2);
            }
            int dist = wall(dir,x,y);
            if(dist == 0){
                dir = (dir + 1) % 4;
                dist = wall(dir,x,y);
            }
            int steps = min(dist,num);
            num -= steps;
            
            x += dx[dir] * steps;
            y += dy[dir] * steps;
            trace(num,x,y);
         }
        cout << endl;
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */