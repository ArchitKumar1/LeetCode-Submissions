// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix

class Solution {
public:
    
    void p(vector<vector<int>> m,int c){
        for(auto x : m){
            for(auto y :x){
                cout << y << " ";
            }
            cout << endl;
        }
        cout << c << endl;
    }
    struct s{
        vector<vector<int>> m;
        int cost;
    };
    int minFlips(vector<vector<int>>& mat) {
        map<vector<vector<int>>,int>m1;
        int n = mat.size();
        int m = mat[0].size();        
        vector<vector<int>>target(n,vector<int>(m,0));
        
        queue<s> qq;
        qq.push({mat,0});
        
        int fans = -1;
        while(qq.size()){
            s t = qq.front();qq.pop();
            if(t.m == target){
                fans = t.cost;
                break;
            }
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    vector<vector<int>> newmat = t.m;
                    newmat[i][j]^=1;
                    for(int x =-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            if(x*x + y*y !=1)continue;
                            int X = i+x;
                            int Y = j+y;
                            if(X < 0 || Y < 0 || X >=n || Y>=m  ) continue;
                            newmat[X][Y]^=1;
                        }
                    }
                    // p(newmat,t.cost);
                    if(m1[newmat] == 0){
                        m1[newmat] = 1;
                        qq.push({newmat,t.cost+1}); 
                    }
                }
            }
        }
        return fans;
    }
};